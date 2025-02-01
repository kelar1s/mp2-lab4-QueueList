#pragma once

template <class T>
struct TNode {
    T val;
    TNode* next = nullptr;
public:
    TNode() : val(T()) {}
    TNode(T value) : val(value) {}
};

template <class T>
class TQueue {
    TNode<T>* pFirst;
    TNode<T>* pLast;
public:
    TQueue();
    TQueue(const TQueue& oth);
    ~TQueue();

    bool operator==(const TQueue& oth) const;
    bool operator!=(const TQueue& oth) const;
    TQueue<T>& operator=(const TQueue& oth);

    bool isEmpty() const { return pFirst == nullptr; }
    bool isFull() const;

    void Clear();

    void Push(T value);
    T Pop();

    T Front() const;
    T Back() const;
};

template <class T>
TQueue<T>::TQueue() {
    pFirst = nullptr;
    pLast = nullptr;
}

template <class T>
TQueue<T>::TQueue(const TQueue& oth) {
    if (oth.pFirst == nullptr) {
        pFirst = nullptr;
        pLast = nullptr;
        return;
    }
    pFirst = new TNode<T>(oth.pFirst->val);
    TNode<T>* tmp = oth.pFirst->next;
    TNode<T>* prev = pFirst;
    while (tmp != nullptr) {
        TNode<T>* node = new TNode<T>(tmp->val);
        prev->next = node;
        tmp = tmp->next;
        prev = prev->next;
    }
    pLast = prev;
}

template <class T>
TQueue<T>::~TQueue() {
    Clear();
}

template <class T>
bool TQueue<T>::operator==(const TQueue& oth) const {
    if (this == &oth) {
        return true;
    }
    TNode<T>* tmp1 = pFirst;
    TNode<T>* tmp2 = oth.pFirst;
    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val != tmp2->val) {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return tmp1 == tmp2;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue& oth) const {
    return !(*this == oth);
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue& oth) {
    if (this == &oth) {
        return *this;
    }
    Clear();
    if (oth.pFirst == nullptr) {
        pFirst = nullptr;
        pLast = nullptr;
        return *this;
    }
    pFirst = new TNode<T>(oth.pFirst->val);
    TNode<T>* tmp = oth.pFirst->next;
    TNode<T>* prev = pFirst;
    while (tmp != nullptr) {
        TNode<T>* node = new TNode<T>(tmp->val);
        prev->next = node;
        tmp = tmp->next;
        prev = prev->next;
    }
    pLast = prev;
    return *this;
}

template <class T>
bool TQueue<T>::isFull() const {
    try {
        TNode<T>* tmp = new TNode<T>();
        delete tmp;
        return false;
    }
    catch (...) {
        return true;
    }
}

template <class T>
void TQueue<T>::Clear() {
    while (pFirst != nullptr) {
        TNode<T>* p = pFirst;
        pFirst = pFirst->next;
        delete p;
    }
    pLast = nullptr;
}

template <class T>
void TQueue<T>::Push(T value) {
    TNode<T>* last = new TNode<T>(value);
    if (pFirst == nullptr) {
        pFirst = last;
        pLast = last;
    }
    else {
        pLast->next = last;
        pLast = last;
    }
}

template <class T>
T TQueue<T>::Pop() {
    if (isEmpty()) {
        throw -1;
    }
    T res = pFirst->val;
    TNode<T>* tmp = pFirst;
    pFirst = pFirst->next;
    if (pFirst == nullptr) {
        pLast = nullptr;
    }
    delete tmp;
    return res;
}

template <class T>
T TQueue<T>::Front() const {
    if (isEmpty()) {
        throw - 1;
    }
    return pFirst->val;
}

template <class T>
T TQueue<T>::Back() const {
    if (isEmpty()) {
        throw - 1;
    }
    return pLast->val;
}
