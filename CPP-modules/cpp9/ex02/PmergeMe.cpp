#include "PmergeMe.hpp"

void mergeInsertSortVec(std::vector<int> &container, int start, int end) {
    int newEnd;

    if (start < end)
    {
        if ((end - start) < 10) {
            insertSortVec(container, start, end);
		}
        else
        {
            newEnd = start + (end - start) / 2;
			std::cout << std::endl;

            mergeInsertSortVec(container,  start, newEnd);
            mergeInsertSortVec(container, newEnd + 1, end);
            mergeSortVec(container, start, newEnd, end);
        }
    }
}

void mergeSortVec(std::vector<int> &container, int start, int mid, int end) {
    int i, j , k;

    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i) {
        left[i] = container[start + i];
	}
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
}

void insertSortVec(std::vector<int> &container, int start, int end) {
  for(int index = start + 1; index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
}

void mergeInsertSortDeq(std::deque<int> &container, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
            insertSortDeq(container, start, end);
        else
        {
            newEnd = start + (end - start) / 2;
            mergeInsertSortDeq(container,  start, newEnd);
            mergeInsertSortDeq(container, newEnd + 1, end);
            mergeSortDeq(container, start, newEnd, end);
        }
    }
}

void mergeSortDeq(std::deque<int> &container, int start, int mid, int end)
{
    int i, j , k;

    std::deque<int> left(mid - start + 1);
    std::deque<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
}

void insertSortDeq(std::deque<int> &container, int start, int end)
{
    for(int index = start + 1; index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
}

void caluclateTime(std::vector<int> &Vcon, std::deque<int> &Dcon,double &vecTime, double &deqTime)
{
    std::clock_t start = std::clock();
    mergeInsertSortVec(Vcon, 0, Vcon.size() - 1);
    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    vecTime = elapsed;
    start = std::clock();
    mergeInsertSortDeq(Dcon, 0, Dcon.size() - 1);
    end = std::clock();
    elapsed = static_cast<double> (end - start) / (CLOCKS_PER_SEC / 1000000.0);
    deqTime = elapsed;
    
}

void print(std::vector<int> &Vec, std::deque<int> &Deq)
{
    static int i = 0;

    if (!i)
        std::cout << "before: ";
    else
        std::cout << "after: "; 

    for (std::vector<int>::iterator it = Vec.begin(); it != Vec.end(); ++it)
		std::cout << *it << " ";
    std::cout << std::endl;

    if (!i)
        std::cout << "before: ";
    else
        std::cout << "after: ";
    
    for (std::deque<int>::iterator it = Deq.begin(); it != Deq.end(); ++it)
		std::cout << *it << " ";
    std::cout << std::endl;
    i++;
}
