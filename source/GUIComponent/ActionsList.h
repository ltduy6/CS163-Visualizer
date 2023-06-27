#pragma once

#include "Container.h"
#include "Button.h"

namespace GUI {
	class ActionsList : public GUI::Container
	{
	public:
		ActionsList(); 
		~ActionsList();
	public:
		void showOptions(std::size_t index); 
		void hideAllOptions(); 
		void ToggleOperations();
	public:
		void draw(Vector2 base = Vector2{ 0, 0 }); 
		void update(float dt);
		void AddOperation(GUI::Button::Ptr action, GUI::Container::Ptr optionContainer);
		void initActionBar();
		Vector2 GetSize();
	private:
		// buttons for several actions
		GUI::Container buttons;
		// list of operations for an action
		GUI::Container optionContainers; 
		bool isVisible; 
	};
}
