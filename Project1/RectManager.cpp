#include "RectManager.h"
#include "Rect.h"
#include<stdexcept>

RectManager::RectNode::RectNode()
{
	this->m_next = NULL;
}

RectManager::RectNode::~RectNode()
{
	delete this->m_data;
}

RectManager::RectNode::RectNode(Rect* rectangle)
{
	this->m_next = NULL;
	this->m_data = rectangle;
}

RectManager::RectNode* RectManager::RectNode::getNext() const
{
	return this->m_next;
}

void RectManager::RectNode::setNext(RectManager::RectNode* nextNode)
{
	this->m_next = nextNode;
}

Rect* RectManager::RectNode::getData() const
{
	return this->m_data;
}

void RectManager::add(Point* rectPoint1, Point* rectPoint2)
{
	Rect* rectangle = new Rect(rectPoint1, rectPoint2);

	this->add(rectangle);
}

int RectManager::getMaxRectangleIndex()
{
	int maxSize = 0;
	int biggestIndex = -1;

	// Loop through the rectangles ands search for the biggest one
	int index = 0;
	for (RectManager::RectNode* curNode = this->m_head; curNode != NULL; curNode = curNode->getNext(), index++) {
		int curRectSize = curNode->getData() == NULL ? 0 : curNode->getData()->area();

		if (curRectSize > maxSize) {
			maxSize = curRectSize;
			biggestIndex = index;
		}
	}

	return biggestIndex;
}

RectManager::RectManager()
{
	this->m_head = NULL;
	this->m_tail = NULL;
}

RectManager::~RectManager()
{
	// Free the whole chain
	RectManager::RectNode* nodeToDelete = this->m_head;
	while (nodeToDelete != NULL)
	{
		//Advance the head
		this->m_head = this->m_head->getNext();

		// Delete the previous head
		delete nodeToDelete;

		// Advance
		nodeToDelete = this->m_head;
	}
}

void RectManager::add(Rect* rectangle)
{
	RectManager::RectNode* rectNode = new RectManager::RectNode(rectangle);

	// No elements at all
	if (this->m_head == NULL) {
		this->m_head = rectNode;
		this->m_tail = rectNode;
	}
	else
	{
		// Let the current tail (that soon going to be the previous tail) to point the new tail
		this->m_tail->setNext(rectNode);

		// Set the new tail
		this->m_tail = rectNode;
	}
}
