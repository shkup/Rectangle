#include "Rect.h"
#include "RectManager.h"
#include <conio.h>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
	Rect* rect1 = new Rect(new Point(2, 5), new Point(-1, 8)); // Size 9
	Rect* rect2 = new Rect(new Point(2, 1), new Point(9, 6)); // Size 35
	Rect* rect3 = new Rect(new Point(-1, -8), new Point(6, 2)); // Size 70
	Rect* rect4 = new Rect(new Point(2, 4), new Point(4, 6)); // Size 4

	// Should be yes
	printf("Rectangle 1 area is %d\r\n", rect1->area());
	printf("Rectangle 2 area is %d\r\n", rect2->area());
	printf("Rectangle 3 area is %d\r\n", rect3->area());
	printf("Rectangle 4 area is %d\r\n", rect4->area());

	RectManager* rectManager = new RectManager();
	rectManager->add(rect1);
	rectManager->add(rect2);
	rectManager->add(rect3);
	rectManager->add(rect4);

	int biggestRectIndex = rectManager->getMaxRectangleIndex();
	printf("The biggest rectangle index is %d\r\n", biggestRectIndex);

	printf("Press any key to exit...");
	_getch();
}