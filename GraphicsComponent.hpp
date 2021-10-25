//
// Created by Дима Щипицын on 28/09/2021.
//

#ifndef ENGINE_GRAPHICSCOMPONENT_HPP
#define ENGINE_GRAPHICSCOMPONENT_HPP

class GameObject;

class GraphicsComponent {
public:
    virtual ~GraphicsComponent() {}
    virtual void update(GameObject& gameObject) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};

#endif //ENGINE_GRAPHICSCOMPONENT_HPP
