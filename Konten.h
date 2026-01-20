#include <cassert>


template <typename T, int ssize >
class Konten {
    //enum { ssize = 100 };
    T queue[ssize];
    int head;
    int tail;
public:
    Konten() : head(0), tail(0) {}

    void push(T i) {
        assert((tail + 1) != head);
        queue[tail] = i;
        tail = (tail + 1);
    }

    T pop() {
        assert(head != tail);
        int v = queue[head];
        head = (head + 1);
        return v;
    }


    class iterator {
        Konten& q;
        int index;
    public:
        iterator(Konten& k, bool end = false): q(k), index(end ? k.tail : k.head) {
        }

        T& operator*() const {
            return q.queue[index];
        }

        iterator& operator++() { // prefix
            assert(index != q.tail);
            index = (index + 1);
            return *this;
        }

        iterator operator++(int) { // postfix
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& rv) const {
            return index == rv.index;
        }
        bool operator!=(const iterator& rv) const {
            return index != rv.index;
        }
    };

    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }

    friend class iterator;
};


