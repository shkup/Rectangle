#pragma once

#include "Rect.h"

class RectManager {
	private: 
		
		class RectNode {
			private:
				Rect* m_data;
				RectNode* m_next;

			public:

				RectNode();

				virtual ~RectNode();

				RectNode(Rect* rectangle);

				RectNode* getNext() const;

				void setNext(RectManager::RectNode* nextNode);

				Rect* getData() const;
			};

		RectManager::RectNode* m_head;
		RectManager::RectNode* m_tail;

	public:

		RectManager();

		virtual ~RectManager();

		void add(Rect* rectangle);

		void add(Point* rectPoint1, Point* rectPoint2);

		int getMaxRectangleIndex();
};
