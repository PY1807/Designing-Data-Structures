class Node
{
    public:
    int key,value,count;
    Node* prev;
    Node* next;
    Node(int k,int v)
    {
        key=k;
        value=v;
        count=1;
    }
};
class List
{
    public:
    Node* head;
    Node* tail;
    int size=0;
    List()
    {
         head=new Node(0,0);
         tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void add(Node* node)
    {
        Node* store=head->next;
        node->next=store;
        node->prev=head;
        head->next=node;
        store->prev=node;
        size++;
    }
    void remove(Node* del)
    {
        Node* delprev=del->prev;
        Node* delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};

class LFUCache {
public:
    map<int,List*>mp;
    map<int,Node*>kN;
    int maxsize;
    int minfreq;
    int size;
    LFUCache(int capacity) {
       maxsize=capacity;
       minfreq=0;
       size=0;

    }
    void update(Node* node)
    {
        mp[node->count]->remove(node);
        kN.erase(node->key);
        if(node->count==minfreq && mp[node->count]->size==0)
        {
            minfreq++;
        }
        List* agli=new List();
        if(mp.find(node->count+1)!=mp.end())
        {
            agli=mp[node->count+1];
        }
        node->count+=1;
        agli->add(node);
        mp[node->count]=agli;
        kN[node->key]=node;
    }
    int get(int key) {
        if(kN.find(key)!=kN.end())
        {
            Node* node=kN[key];
            int value=node->value;
            update(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(kN.find(key)!=kN.end())
        {
            Node* node=kN[key];
            node->value=value;
            update(node);
        }
        else
        {
            if(size==maxsize)
            {
                List* list=mp[minfreq];
                kN.erase(list->tail->prev->key);
                list->remove(list->tail->prev);
                size--;
            }
            size++;
            minfreq=1;
            List* list=new List();
            if(mp.find(minfreq)!=mp.end())
            {
              list=mp[minfreq];
            }
            Node* node=new Node(key,value);
            list->add(node);
            kN[key]=node;
            mp[minfreq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
