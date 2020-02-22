////
//// Created by hmys on 2019/10/18.
////
//
//
//#include <cstdlib>
//#include <malloc.h>
//#include <queue>
//
//using namespace std;
//
//typedef int DateType;
//struct SeqQueue {
//	int MAXIMUM;
//	int f, r;
//	DateType *data;
//};
//typedef struct SeqQueue *PSeQueue;
//
//void print(int location, int oldLocation) {
//	if ((location & 0x01) && (oldLocation & 0x01))
//		printf("Ñò|\t|\n");
//	else if (!(location & 0x01) && (oldLocation & 0x01))
//		printf("Ñò|->\t|  \n");
//	else if (!(location & 0x01) && !(oldLocation & 0x01))
//		printf("  |\t|Ñò\n");
//	else if ((location & 0x01) && !(oldLocation & 0x01))
//		printf("  |<-\t|Ñò\n");
//
//	if ((location & 0x02) && (oldLocation & 0x02))
//		printf("²Ë|\t|\n");
//	else if (!(location & 0x02) && (oldLocation & 0x02))
//		printf("²Ë|->\t|  \n");
//	else if (!(location & 0x02) && !(oldLocation & 0x02))
//		printf("  |\t|²Ë\n");
//	else if ((location & 0x02) && !(oldLocation & 0x02))
//		printf("  |<-\t|²Ë\n");
//
//	if ((location & 0x04) && (oldLocation & 0x04))
//		printf("ÀÇ|\t|\n");
//	else if (!(location & 0x04) && (oldLocation & 0x04))
//		printf("ÀÇ|->\t|  \n");
//	else if (!(location & 0x04) && !(oldLocation & 0x04))
//		printf("  |\t|ÀÇ\n");
//	else if ((location & 0x04) && !(oldLocation & 0x04))
//		printf("  |<-\t|ÀÇ\n");
//
//	if ((location & 0x08) && (oldLocation & 0x08))
//		printf("Å©|\t|\n");
//	else if (!(location & 0x08) && (oldLocation & 0x08))
//		printf("Å©|->\t|  \n");
//	else if (!(location & 0x08) && !(oldLocation & 0x08))
//		printf("  |\t|Å©\n");
//	else if ((location & 0x08) && !(oldLocation & 0x08))
//		printf("  |<-\t|Å©\n");
//
//	printf("\n\n\n");
//}
//
//
//int farmer(int location) {
//	return (0 != (location & 0x08));
//}
//
//int wolf(int location) {
//	return (0 != (location & 0x04));
//}
//
//int cabbage(int location) {
//	return (0 != (location & 0x02));
//}
//
//int goat(int location) {
//	return (0 != (location & 0x01));
//}
//
//int safe(int location) {
//	if (goat(location) == cabbage(location) && (goat(location) != farmer(location)))
//		return 0;
//	if (goat(location) == wolf(location) && (goat(location) != farmer(location)))
//		return 0;
//	return 1;
//}
//
//void farmerProblem() {
//	int i, movers, location, newLocation, oldLocation;
//	int route[16];
//	queue<DateType> moveTo;
//	moveTo.push(0x00);
//	for (i = 0; i < 16; i++) route[i] = -1;
//	route[0] = 0;
//	while (!moveTo.empty() && (route[15] == -1)) {
//		location = moveTo.front();
//		moveTo.pop();
//		for (movers = 1; movers <= 8; movers <<= 1)
//			if ((0 != (location & 0x08)) == (0 != (location & movers))) {
//				newLocation = location ^ (0x08 | movers);
//				if (safe(newLocation) && (route[newLocation] == -1)) {
//					route[newLocation] = location;
//					moveTo.push(newLocation);
//				}
//			}
//	}
//	if (route[15] != -1) {
//		system("cls");
//		for (oldLocation = location = 15; location >= 0; location = route[location]) {
//			printf("The path is:\n");
//			print(location, oldLocation);
//			oldLocation = location;
//			printf("\n\n\n\n\n°´»Ø³µ¼ÌÐø\n\n");
//			getchar();
//			system("cls");
//			if (location == 0) {
//				printf("success!\n");
//				print(location, oldLocation);
//				exit(0);
//			}
//		}
//
//	}
//	else printf("NO result!\n");
//}
//
//
//int main() {
//	farmerProblem();
//}