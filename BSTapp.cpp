#include <iostream>
#include"Node.h"
#include"BST.h"
#include"windows.h"

using namespace std;

template<class T>
void menu(BST<T>& b) {
	int in;
	cout << "Enter\n\
1 to Insert\n\
2 to Pre-Order Walk\n\
3 to In-Order Walk\n\
4 to Post-Order Walk\n\
5 to Level Order Walk\n\
6 to Remove\n\
7 for Size\n\
8 for Mirror\n\
9 for Minimun\n\
10 for Maximum\n\
11 for Sum\n\
12 for Leafs\n\
13 for Intermidiate\n\
14 for Parent\n\
15 for Successor\n\
16 for Predecessor\n\
17 for Height\n\
18 for Balance Factor\n\
19 for Greater Sum Tree\n\
20 to exit: ";
	cin >> in;
	while (in < 1 || in>20) {
		cout << "Invalid Input\nEnter Again: ";
		cin >> in;
	}
	if (in == 1) {
		int v;
		cout << "Value ? : ";
		cin >> v;
		b.insert(v);
		cout << "Inserted Successfully!\n";
	}
	else if (in == 2) {

		if (b.getRoot()) {
			cout << endl;
			b.walkPreOrder(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 3) {
		if (b.getRoot()) {
			cout << endl;
			b.walkInOrder(b.getRoot());
			cout << endl;	
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 4) {
		if (b.getRoot()) {
			cout << endl;
			b.walkPostOrder(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 5) {
		if (b.getRoot()) {
			cout << endl;
			b.levelOrder(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 6) {
		if (b.getRoot()) {
			int v;
			cout << "Remove ? : ";
			cin >> v;
			b.remove(v);
			cout << "Removed Successfully!\n";
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 7) {
		if (b.getRoot()) {
			cout << endl << "Size: " <<	b.getSize() << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 8) {
		if (b.getRoot()) {

			BST<T>* b1 = new BST<T>;
			cout << endl << "Mirror of: \n";
			b.levelOrder(b.getRoot());
			cout <<"is:"<< endl;
			b.mirror(b.getRoot(), b1);
			b1->levelOrder(b1->getRoot());
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 9) {
		if (b.getRoot()) {
			cout << endl << "Min: " << b.minn(b.getRoot()) << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 10) {
		if (b.getRoot()) {
			cout << endl << "Max: " << b.maxx(b.getRoot()) << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 11) {
		if (b.getRoot()) {
			cout << endl << "Sum: " << b.sum(b.getRoot()) << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 12) {
		if (b.getRoot()) {

			cout << endl;
			b.allLeafsDisplay(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 13) {
		if (b.getRoot()) {

			cout << endl;
			b.allInterDisplay(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 14) {
		if (b.getRoot()) {

			cout << endl;
			int v;
			cout << "Parent of ? : ";
			cin >> v;
			cout << b.parentDisplay(v) << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 15) {
		if (b.getRoot()) {

			cout << endl;
			int v;
			cout << "Successor of ? : ";
			cin >> v;
			b.successor(v);
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 16) {
		if (b.getRoot()) {

			cout << endl;
			int v;
			cout << "Predecessor of ? : ";
			cin >> v;
			b.predecessor(v);
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 17) {
		if (b.getRoot()) {
			cout << endl << "Height: " << b.high(b.getRoot()) << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 18) {
		if (b.getRoot()) {

			cout << endl;
			int v;
			cout << "Check Balance ? : ";
			cin >> v;
			b.balanceFactor(v) ? cout << "Balanced!\n" : cout << "Not Balanced!\n";
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 19) {
		if (b.getRoot()) {
			cout << endl<<"GST of: \n";
			b.levelOrder(b.getRoot());
			cout << "is:\n";
			b.gst();
			b.levelOrder(b.getRoot());
			cout << endl;
		}
		else cout << "Empty Tree!\n";
	}
	else if (in == 20) {
		exit(0);
	}
}
int main()
{
	BST<int> b;
	char in;
	do {
		Sleep(500);
		system("cls");
		menu(b);
		cout << "Enter any key to continue: ";
		cin >> in;
	} while (in);
}
