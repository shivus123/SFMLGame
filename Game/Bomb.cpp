#include "Bomb.h"

Bomb::Bomb(std::shared_ptr<Context> context, std::shared_ptr<sf::Vector2f> poss) :
    Entity(context, poss, 100), left(false), right(false), up(false), down(false), speed(10.f)
{
}

Bomb::~Bomb()
{
}

void Bomb::getHit(int dir)
{
    //  have to implement a stop mechanism i guess ,o,
    if (dir == 0)
    {
        this->right = true;
        this->left = false;
        this->up = false;
        this->down = false;
    }
    else if (dir == 1)
    {
		this->right = false;
        this->left = true;
        this->up = false;
        this->down = false;
    }
    else if (dir == 2)
    {
        this->right = false;
        this->left = false;
        this->up = false;
        this->down = true;
    }
    else
    {
        this->right = false;
        this->left = false;
        this->up = true;
        this->down = false;
    }
}

void Bomb::update(sf::Time deltaTime)
{
    if (up)
    {
        this->pos->move({ 0, -speed });
    }
    else if (down)
    {
        this->pos->move({ 0, speed });
    }
    else if (right)
    {
        this->pos->move({ speed, 0 });
    }
    else if (left)
    {
        this->pos->move({ -speed, 0 });
    }
    health--;
}

void Bomb::update(sf::Time deltaTime, std::shared_ptr<std::vector<std::vector<int>>> m_Field)
{
    //  get old position so we can delete this entry later maybe?

    //  stop bombs if necessary
    //if ()

    update(deltaTime);

    //  set positions in the field


}

void Bomb::render()
{
    if (health > 80)
        this->pos->setFillColor({ 150, 100, 100 });
    else if (health > 60)
        this->pos->setFillColor({ 200, 100, 100 });
    else if (health > 40)
        this->pos->setFillColor({ 220, 120, 120 });
    else if (health > 20)
        this->pos->setFillColor({ 240, 150, 150 });
    else
        this->pos->setFillColor({ 255, 180, 180 });
    
    this->m_context->m_window->draw(*this->pos);
}

bool Bomb::goesBoom()
{
    return health <= 0;
}
