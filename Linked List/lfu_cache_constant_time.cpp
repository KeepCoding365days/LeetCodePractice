struct Node {
    int val;
    int key;
    int counter;
    std::list<int>::iterator listIterator;

    Node() {
        key = 0;
        val = 0;
        counter = 0;

    }
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->counter = 1;

    }
};
class LFUCache {
    unordered_map<int, Node> map;
    unordered_map<int, std::list<int>> freqList;
    int capacity;
    int tot_elem;
    int min_freq;
public:
    LFUCache(int capacity) {
        if (capacity >= 0) {
            this->capacity = capacity;
        }
        tot_elem = 0;
        min_freq = 0;
        cout<<capacity;
    }

    int get(int key) {

        int ret = -1;
        if (map.find(key) != map.end()) {
            ret = map.find(key)->second.val;
           
            int prev_freq=map[key].counter;
            map[key].counter++;
            //Node n1=map[key];
           
            freqList[prev_freq].erase(map[key].listIterator);
            freqList[prev_freq+1].push_front(key);
            map[key].listIterator=freqList[prev_freq+1].begin();
            if(freqList[prev_freq].empty()&& prev_freq==min_freq){
                min_freq=prev_freq+1;
            }
        }

        return ret;

    }

    void put(int key, int value) {
        if (capacity > 0) {
            if (map.find(key) == map.end()) {
                if (tot_elem < capacity) {
                    Node n1(key, value);
                    map.insert(make_pair(key,n1));
                    freqList[1].push_front(key);
                    map[key].listIterator=freqList[1].begin();
                    min_freq=1;
                    
                }
                else {
                    int key_d=freqList[min_freq].back();
                    freqList[min_freq].pop_back();
                    
                    map.erase(key_d);
                    Node n1(key, value);
                    map.insert(make_pair(key, n1));
                    
                    min_freq=1;
                    freqList[min_freq].push_front(key);
                    map[key].listIterator=freqList[min_freq].begin();

                }
                
                tot_elem++;
            }
            else {
                map[key].val = value;
                int prev_freq=map[key].counter;
                map[key].counter++;
                
                
                freqList[prev_freq].erase(map[key].listIterator);
                freqList[prev_freq+1].push_front(key);
                map[key].listIterator=freqList[prev_freq+1].begin();
                if(freqList[prev_freq].empty()&& prev_freq==min_freq){
                    min_freq=prev_freq+1;
                }

                
            }

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */