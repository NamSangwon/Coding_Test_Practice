#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Heap
{
private:
    vector<T> heap;
    void swap(int curr_idx, int target_idx)
    {
        T temp = heap[curr_idx];
        heap[curr_idx] = heap[target_idx];
        heap[target_idx] = temp;
    }
    bool compare(T a, T b)
    {
        return a > b;
    }

public:
    void push(T num)
    {
        heap.push_back(num);

        // Bottom Up (마지막 원소 위치 이동)
        int pos = heap.size() - 1;
        while(true)
        {
            int parent = (pos - 1) / 2;

            if (parent < 0) 
                break;

            if (compare(heap[pos], heap[parent]))
            {
                swap(pos, parent);
            }
            else
                break;

            pos = parent;
        }
    }
    void pop()
    {
        if (heap.empty()) return;

        heap[0]  = heap.back();
        heap.pop_back();

        // Top Down (첫번째 원소 위치 이동)
        int pos = 0;
        while(true)
        {
            int left_child = pos * 2 + 1;
            int right_child = pos * 2 + 2;
            int largest = pos;

            if (right_child < heap.size())
            {
                if (compare(heap[left_child], heap[right_child]))
                {
                    largest = left_child;
                }
                else
                {
                    largest = right_child;
                }
            }
            else if (left_child < heap.size())
            {
                largest = left_child;
            }
            else 
                break;

            if (compare(heap[largest], heap[pos]))
            {
                swap(pos, largest);
                pos = largest;
            }
            else 
                break;
        }
    }
    T top() 
    { 
        return (empty() ? 0 : heap[0]); 
    }
    bool empty() 
    { 
        return heap.empty(); 
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Heap<unsigned int> pq;
    for (int i = 0; i < N; i++)
    {
        unsigned int num;
        cin >> num;

        if (num == 0)
        {
            if (pq.empty()) 
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
}