#pragma once
#include "Algorithm.h"
#include "../Helper/GlobalVar.h"

namespace Algorithms {
	class AVL : public Algorithm
	{
	public:
		static constexpr Vector2 STARTING_POINT = Vector2{ Constant::WINDOW_WIDTH / 2, 100 };
		static constexpr float RADIUS = 20;
		float VERTICAL_SPACE = 100;
		float HORIZONTAL_SPACE = 50;
		float MODIFIER = 0;
	public:
		AVL(Visualize::Visualization& visualization); 
		~AVL(); 
	public:
		void InitRandomFixSize(int size); 
		void Init(std::vector<int>& list);
		void Insert(int value); 
	private:
		class Node {
		public:
			typedef std::shared_ptr<Node> Ptr; 
			Node() : left{ nullptr }, right{ nullptr }, parent{ nullptr } {};
		public:
			int value{ 0 };
			int id{ 0 };
			int height{ 1 };
			int Alignment{ 0 };
			int idEdgeLeft{ 0 }; 
			int idEdgeRight{ 0 };
			int idEdge{ 0 }; 

			Node::Ptr left; 
			Node::Ptr right; 
			Node::Ptr parent;

			std::map<int, std::string> references; 
		};
	private:
		int mSize{ 0 }; 
		int mHeight{ 0 };
		Node::Ptr mRoot{ nullptr };
		Node::Ptr mVisual{ nullptr };
		bool finishRotation{ true };
	private:
		void sceneReset();
	private:
		Node::Ptr InitUntil(Node::Ptr& root, Node::Ptr& parent, int value);
		Node::Ptr SortedArrayToAVL(std::vector<int>& nums, int start, int end);
		Node::Ptr rotateLeft(Node::Ptr& root); 
		Node::Ptr rotateRight(Node::Ptr& root); 
		Node::Ptr searchValue(Node::Ptr root, int value);
		Node::Ptr copyTree(Node::Ptr root);
		void RotateUntil(Node::Ptr& root, Node::Ptr& visual, int value);
		void traverse(Node::Ptr& root, Vector2 pos, int level, int& count); 
		void modifyDistance(Node::Ptr& root);
		void BalanceTree(Node::Ptr& root);
		void addEdge(Node::Ptr& root); 
		int Height(Node::Ptr root);
		int Width(Node::Ptr root);
		int countNode(Node::Ptr root);
		int getBalance(Node::Ptr root);
	};
}
