#include <iostream>
using namespace std;

void Assert(bool val, string s) {
	if (!val) {
		cout << "Assertion Failed:" << s << endl;
		exit(-1);
	}
}

template <typename E> class AList {
	private:
		int maxSize;
		int listSize;
		int curr;
		E *listArray;

	public:
		AList(int size = 10) {
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}

		~AList() {
			delete[] listArray;
		}

		void clear() {
			delete[] listArray;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}
		void insert(const E &it) {
			Assert(listSize < maxSize, "List capacity exceeded");
			for (int i = listSize; i > curr; i--) {
				listArray[i] = listArray[i - 1];
				listArray[curr] = it;
				listSize++;
			}
		}
		void append(const E &it) {
			Assert(listSize < maxSize, "List capacity exceeded");
			listArray[listSize++] = it;
		}
		E remove() {
			Assert((curr >= 0) && (curr < listSize), "No element");
			E it = listArray[curr];
			for (int i = curr; i < listSize - 1; i++) {
				listArray[i] = listArray[i + 1];
				listSize--;
				return it;
			}
		}
		void moveToStart() {
			curr = 0;
		}
		void moveToEnd() {
			curr = listSize;
		}
		void prev() {
			if (curr != 0)
				curr--;
		}
		void next() {
			if (curr < listSize)
				curr++;
		}
		int length() const {
			return listSize;
		}
		int currPos() const {
			return curr;
		}
		void moveToPos(int pos) {
			Assert((pos >= 0) && (pos <= listSize), "Pos out of range");
			curr = pos;
		}

		const E &getValue() const {
			Assert((curr >= 0) && (curr < listSize), "No current element");
			return listArray[curr];
		}

};


void print(AList<int> &list) {
	list.moveToStart();
	while (list.currPos() < list.length()) {
		cout << list.getValue() << " ";
		list.next();
	}
	cout << endl;
}

int main() {
	AList<int> list;
	list.append(1);
	list.append(2);
	print(list);

	return 0;
}