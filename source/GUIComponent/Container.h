#pragma once
#include "Component.h"
#include <memory>
#include <vector>

namespace GUI {
	class Container : public Component
	{
	public:
		typedef std::shared_ptr<Container> Ptr; 
	public:
		Container();

		void pack(Component::Ptr component);
		void unpack();

		virtual void draw(Vector2 basePos = Vector2{0, 0});
		virtual void update(float dt);
		virtual bool isSelectable() const; 

		virtual void drawCurrent(Vector2 basePos);

		virtual Vector2 Getsize(); 
		std::vector<GUI::Component::Ptr> getChildren();
	protected:
		std::vector<GUI::Component::Ptr> mChildren;
	};
}
