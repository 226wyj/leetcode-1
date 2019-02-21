struct Node {
	int key, value;
	struct Node *prev, *next;
};
class LRUCache {
	private:
		int capacity, sz;
		unordered_map<int, Node*> lookup;
		Node *head, *tail;
		// update node to tail
		void update(Node *node, bool needUpdate = false, int _value = 0) {
			if (needUpdate) node -> value = _value;
			if (node == tail || head == tail) return;
			if (head == node) head = head -> next;
			// connect prev with next: skip current node
			if (node -> prev) node -> prev -> next = node -> next;
			// connect next with prev: skip current node
			if (node -> next) node -> next -> prev = node -> prev;
			node -> next = NULL;
			tail -> next = node;
			node -> prev = tail;
			tail = node;
		}

		void add(int key, int value) {
			if (sz == capacity) {
				Node *cur = lookup[head -> key];
				if (head -> next) head -> next -> prev = NULL;
				if (head == tail) head = tail = NULL;
				else head = head -> next;
				lookup.erase(cur -> key);
				free(cur);
				sz--;
			}
			Node *newNode = (Node *)malloc(sizeof(Node));
			newNode -> key = key;
			newNode -> value = value;
			newNode -> prev = newNode -> next = NULL;
			lookup[key] = newNode;

			if (!head) head = tail = newNode;
			else {
				tail -> next = newNode;
				newNode -> prev = tail;
				tail = newNode;
			}
			sz++;
		}
	public:
		LRUCache(int _capacity) {
			capacity = _capacity;
			sz = 0;
			lookup.clear();
			head = NULL;
			tail = NULL;
		}

		int get(int key) {
			if (lookup.find(key) != lookup.end()) {
				update(lookup[key]);
				return lookup[key] -> value;
			}
			return -1;
		}

		void put(int key, int value) {
			if (lookup.find(key) == lookup.end())
				add(key, value);
			else
				update(lookup[key], true, value);
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
