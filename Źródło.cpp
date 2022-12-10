#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

// Stan gry
constexpr int fieldWidth = 10;
constexpr int fieldHeight = 20;
constexpr int blockSize = 30;
int field[fieldWidth * fieldHeight] = { 0 };

// Rakietka
constexpr int paddleWidth = 80;
constexpr int paddleHeight = 20;
int paddlePos = 0;

// Pi³eczka
constexpr int ballRadius = 10;
int ballPosX = 0;
int ballPosY = 0;
int ballDirX = 1;
int ballDirY = 1;

// Power-upy
enum class PowerUpType
{
    NONE,
    LONG_PADDLE,
    SHORT_PADDLE,
    FAST_BALL,
    SLOW_BALL,
    EXTRA_LIFE
};
constexpr int powerUpChance = 10; // szansa na pojawienie siê power-upu (w %)
PowerUpType powerUp = PowerUpType::NONE;
constexpr int powerUpDuration = 30; // trwanie power-upu (w klatkach)
int powerUpTimer = 0;

// Punktacja i ¿ycia
int score = 0;
constexpr int lives = 3;
int currentLives = lives;

// Koniec gry
bool isGameOver = false;

// Rysowanie klocków na planszy
void drawBlocks(sf::RenderWindow& window)
{
    for (int x = 0; x < fieldWidth; x++)
    {
        for (int y = 0; y < fieldHeight; y++)
        {
            // Je¿eli pole na planszy jest zajête przez klocek,
            // rysujemy go na ekranie
            if (field[x + y * fieldWidth] != 0)
            {
                sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));
                block.setPosition(x * blockSize, y * blockSize);
                block.setFillColor(sf::Color::Blue);
                window.draw(block);
            }
        }
    }
}

// Rysowanie rakietki
void drawPaddle(sf::RenderWindow& window)
{
    int paddleWidthMod = paddleWidth;
    if (powerUp == PowerUpType::LONG_PADDLE)
        paddleWidthMod *= 1.5;
    else if (powerUp == PowerUpType::SHORT_PADDLE)
        paddleWidthMod /= 2;

    sf::RectangleShape paddle(sf::Vector2f(paddleWidthMod, paddleHeight));
    paddle.setPosition(paddlePos, fieldHeight * blockSize - paddleHeight);
    paddle.setFillColor(sf::Color::Red);
    window.draw(paddle);
}

// Rysowanie pi³eczki
void drawBall(sf::RenderWindow& window)
{
    sf::CircleShape ball(ballRadius);
    ball.setPosition(ballPosX - ballRadius, ballPosY - ballRadius);
    ball.setFillColor(sf::Color::Green);
    window.draw(ball);
}

// Rysowanie napisu koñca gry
void drawGameOver(sf::RenderWindow& window)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text gameOverText("Game Over!", font, 40);
    gameOverText.setPosition(fieldWidth * blockSize / 2 - gameOverText.getLocalBounds().width / 2,
        fieldHeight * blockSize / 2 - gameOverText.getLocalBounds().height / 2);
    gameOverText.setFillColor(sf::Color::White);
    window.draw(gameOverText);
}

// Aktualizacja stanu gry
void updateGame()
{
    // Aktualizacja pozycji pi³eczki
    ballPosX += ballDirX;
    ballPosY += ballDirY;

    // Odbicie od œcian
    if (ballPosX < 0 || ballPosX > fieldWidth * blockSize)
        ballDirX *= -1;
    if (ballPosY < 0)
        ballDirY *= -1;

    // Odbicie od rakietki
    if (ballPosY > fieldHeight * blockSize - paddleHeight &&
        ballPosX >= paddlePos && ballPosX <= paddlePos + paddleWidth)
    {
        ballDirY *= -1;

        // Losowanie power-upu
        if (powerUp == PowerUpType::NONE)
        {
            int chance = rand() % 100;
            if (chance < powerUpChance)
            {
                int type = rand() % 5;
                switch (type)
                {
                case 0:
                    powerUp = PowerUpType::LONG_PADDLE;
                    break;
                case 1:
                    powerUp = PowerUpType::SHORT_PADDLE;
                    break;
                case 2:
                    powerUp = PowerUpType::FAST_BALL;
                    break;
                case 3:
                    powerUp = PowerUpType::SLOW_BALL;
                    break;
                case 4:
                    powerUp = PowerUpType::EXTRA_LIFE;
                    break;
                }
            }
        }

        // Zwiêkszenie prêdkoœci pi³eczki po odbiciu
        ballDirX *= 1.05;
        ballDirY *= 1.05;
    }

    // Odbicie od klocków
    int blockX = ballPosX / blockSize;
    int blockY = ballPosY / blockSize;
    if (field[blockX + blockY * fieldWidth] != 0)
    {
        field[blockX + blockY * fieldWidth] = 0;
        ballDirY *= -1;
        score += 10;
    }

    // Aktualizacja power-upów
    if (powerUp != PowerUpType::NONE)
    {
        powerUpTimer++;
        if (powerUpTimer >= powerUpDuration)
        {
            powerUp = PowerUpType::NONE;
            powerUpTimer = 0;
        }
    }

    // Zmiana prêdkoœci pi³eczki w przypadku power-upów
    if (powerUp == PowerUpType::FAST_BALL)
    {
        ballDirX *= 1.5;
        ballDirY *= 1.5;
    }
    else if (powerUp == PowerUpType::SLOW_BALL)
    {
        ballDirX *= 0.5;
        ballDirY *= 0.5;
    }

    // Aktualizacja ¿ycia po up³ywie pi³eczki poza ekran
    if (ballPosY > fieldHeight * blockSize)
    {
        currentLives--;
        if (currentLives == 0)
        {
            isGameOver = true;
            return;
        }

        // Powrót do pocz¹tkowej pozycji
        ballPosX = fieldWidth * blockSize / 2;
        ballPosY = fieldHeight * blockSize / 2;
        ballDirX = (rand() % 2 == 0) ? 1 : -1;
        ballDirY = (rand() % 2 == 0) ? 1 : -1;
    }

    // Aktualizacja pozycji rakietki
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        paddlePos -= 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        paddlePos += 3;

    // Ograniczenie ruchu rakietki do obszaru planszy
    if (paddlePos < 0)
        paddlePos = 0;
    if (paddlePos > fieldWidth * blockSize - paddleWidth)
        paddlePos = fieldWidth * blockSize - paddleWidth;
}

int main()
{
    srand(time(nullptr));

    // Inicjalizacja okna gry
    sf::RenderWindow window(sf::VideoMode(fieldWidth * blockSize, fieldHeight * blockSize), "Arkanoid");

    // Inicjalizacja pocz¹tkowej pozycji pi³eczki
    ballPosX = fieldWidth * blockSize / 2;
    ballPosY = fieldHeight * blockSize / 2;

    // Inicjalizacja planszy z klockami
    for (int i = 0; i < fieldWidth * fieldHeight; i++)
        field[i] = 1;

    // Pêtla g³ówna
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Aktualizacja stanu gry
        updateGame();

        // Czyszczenie ekranu
        window.clear();

        // Rysowanie elementów gry
        drawBlocks(window);
        drawPaddle(window);
        drawBall(window);
        if (isGameOver)
            drawGameOver(window);

        // Wyœwietlanie ekranu
        window.display();
    }

    return 0;
}