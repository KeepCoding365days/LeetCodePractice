class AllOne {
    unordered_map<string,int> map;
    list<string>freq;

    vector<list<string>>freq_list;
    int max_freq;
    int min_freq;
    int freq_size=0;
public:
    AllOne() {
        max_freq=0;
        min_freq=0;
        freq_size=10;
        //for(int i=0;i<10;i++){
            //freq_list.push_back(list<string>);
        //}
        freq_list.resize(10);
    }
    
    void inc(string key) {
        if(map.find(key)==map.end()){
            map.insert(make_pair(key,1));
            min_freq=1;
            freq_list[1].push_front(key);
            if(min_freq>=max_freq){
                max_freq=min_freq;
            }
        }
        else{
            map[key]=map[key]+1;
            int freq=map[key];
            if(freq>freq_size-1){
            list<string> l;
                freq_list.push_back(l);
            }
            freq_list[freq].push_front(key);
            freq_list[freq-1].remove(key);
            if(freq>=max_freq){
                max_freq=freq;
            }
            if(freq-1==min_freq && freq_list[freq-1].size()==0){
                min_freq=freq;
            }

        }
    }
    
    void dec(string key) {
        int freq=0;
        if(map.find(key)!=map.end()){
            map[key]=map[key]-1;
            freq=map[key];
            if(map[key]==0){
                map.erase(key);
            }
        }
        freq_list[freq+1].remove(key);
        if(freq+1==max_freq && freq_list[freq+1].size()==0){
            max_freq=max_freq-1;
        }
        
        if(freq!=0){
        freq_list[freq].push_front(key);
        if(freq<min_freq){
            min_freq=freq;
        }
        }
        else if(min_freq==1 && freq_list[1].size()==0){
            int i=0;
            while(i<freq_list.size()-1 && freq_list[i].size()==0){
                i=i+1;
            }
            min_freq=i;
        }
        
        
        
        
    }
    
    string getMaxKey() {
        string a="";
        if(freq_list[max_freq].size()!=0){
            a=freq_list[max_freq].front();
        }
        return a;
    }
    
    string getMinKey() {
        string a="";
        if(freq_list[min_freq].size()!=0){
            a=freq_list[min_freq].front();
        }
        return a;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */