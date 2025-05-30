#pragma once
#include "Transform.h"
#include "Renderer.h"
#include "string"
#include "memory"
#include "vector"
#include "glut.h"

class GameObject
{
private:
	std::string _name;
	bool _active = true;

    std::vector<std::unique_ptr<Component>> _components;
public:

    GameObject(const std::string& name = "GameObject");

    void update(float deltaTime);
    void render();

    /**
    * Adds a new component of type T to the GameObject.
    *
    * This method constructs the component with the given arguments,
    * sets its owner to this GameObject, stores it internally,
    * and returns a raw pointer to the component.
    *
    * @tparam T The type of the component to add (must derive from Component).
    * @tparam Args Variadic template for constructor arguments of T.
    * @param args Arguments forwarded to the component constructor.
    * @return A raw pointer to the newly created component.
    */

    template<typename T, typename... Args>
    T* addComponent(Args&&... args);

    /**
     * Retrieves the first component of type T attached to this GameObject.
     *
     * This method searches through all components and returns the first one
     * that can be dynamically cast to type T. If no such component exists,
     * returns nullptr.
     *
     * @tparam T The type of component to retrieve.
     * @return Pointer to the component if found, nullptr otherwise.
     */
    template<typename T>
    T* getComponent();

    void setActive(bool value);
    bool isActive();

    std::string getName();
};
