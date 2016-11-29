// Design a data structure data would do put(K key, V value), V remove(K key) and V removeRandom() in O(1).

// eg: 
// vector = [0 1 3 4 ]
// HashTable = <0, 0>, <1, 1>, <3, 3> <4, 2>

template <typename K, template V>
class KVStore {
    
    public:
        KVStore(uint64_t initial_size=100) : 
                size_(size) {
            store_ = new HashTable<K, V>(initial_size);
        }
        
        ~KVStore() {
            Assert ( this->store_ !- nullptr );
            delete this->store_;
        }
        
        int put(K& key, V& value);
        
        V remove(K& key);
        
        V removeRandom();
        
    private:
        // internal methods
        void _grow();
        K _pick_random_key();
        
        uint64_t size_;
        HashTable<K, std::pair<V, uint64_t>> *store_;
        vector<K> keys_;
};

int KVStore::put(K& key, V& value)
{
    if ( this->store_->size() == size_) ) {
        _grow(store_);
    }
    keys_.append(key);
    store_[key] = std::make_pair(value, keys_.size()-1);

    return 0;
}


V KVStore::remove(K& key)
{
    if ( store_->find(key) == store_->end() ) {
        throw ValueErrror();
    }
    
    auto value = store_[key];
    store_->remove(key.first);
    
    store_[keys_[keys_.size()-1]].second = key.second;
    swap(keys_, key.second, keys_.size()-1);

    keys_.remove(keys_.size()-1);
    return value;
}

V KVStore::removeRandom()
{
    // pick a key from a range of existing keys
    auto key = _pick_random_key();
    return this->remove(key);
}

void KVStore::_grow()
{
    size_ = size_ * 2;
    // 
}

K KVStore::_pick_random_key()
{
    uint64_t start = 0, end = keys_.size()-1;
    return keys_[choose_random(start, end)];
}


