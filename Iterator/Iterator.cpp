#include <iostream>
#include <vector>
#include <string>

template<typename T>
bool binarySearch(T sought, const std::vector<T>& numbers)
{
    auto begin = numbers.begin(), end = numbers.end();
    auto mid = begin + (end - begin) / 2;

    while (mid != end)
    {
        if (sought > * mid)
            begin = mid + 1;
        else if (sought < *mid)
            end = mid;
        else
            return true;
        mid = begin + (end - begin) / 2;
    }
    return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector)
{
    std::string vectorStr;
    for (auto current = vector.begin(); current != vector.end(); current++)
        if (current == vector.begin())
            vectorStr += std::to_string(*current);
        else
            vectorStr += ", " + std::to_string(*current);
    stream << vectorStr;
    return stream;
}

int main()
{
    std::vector<int> intVector = { 1, 3, 4, 7, 10, 32, 44, 100 };
    bool hasFindIntVector = binarySearch(1, intVector);
    std::cout << "hasFindIntVector: " << hasFindIntVector << std::endl;

    std::vector<double> doubleVector = { 1.4, 3.7, 4.2, 7.5, 10.9, 32.3, 44.6, 100.8 };
    bool hasFindDoubleVector = binarySearch(1.4, doubleVector);
    std::cout << "hasFindDoubleVector: " << hasFindDoubleVector << std::endl;

    std::vector<float> floatVector = { 1.4f, 3.7f, 4.2f, 7.5f, 10.9f, 32.3f, 44.6f, 100.8f };
    bool hasNotFindFloatVector = binarySearch(1.5f, floatVector);
    std::cout << "hasNotFindFloatVector: " << hasNotFindFloatVector << std::endl;

    // Some container member functions using iterators

    // insert (before iterator (first parameter))
    std::vector<int> insertVector = { 1, 2, 4, 5, 6 };
    // single element
    insertVector.insert(insertVector.begin(), 0);
    insertVector.insert(insertVector.end(), 7);
    insertVector.insert(insertVector.begin() + 3, 3);

    std::vector<int> inputVector = { 8, 9, 10 };
    // range
    insertVector.insert(insertVector.end(), inputVector.begin(), inputVector.end() - 1);

    // initializer list
    insertVector.insert(insertVector.begin(), { -2, -1 });

    std::cout << "insertVector: " << insertVector << std::endl;

    // access
    std::vector<int> accessVector = { 1, 2, 4, 5, 6 };
    
    int& front = accessVector.front();
    int& back = accessVector.back();
    int& at = accessVector.at(2);
    front = 0;
    back = 8;
    at = 3;
    std::cout << "accessVector: " << accessVector << std::endl;

    try
    {
        // Only at function throws exception
        accessVector.at(10);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // delete
    std::vector<int> deleteVector = { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 };

    deleteVector.erase(deleteVector.end() - 1);
    deleteVector.erase(deleteVector.begin(), deleteVector.begin() + 1);

    // std::remove return an iterator to the element that follows the last element not removed (Past-the-end iterator for the new range of values)
    // The range between begin() this iterator includes all the elements in the sequence that do not compare equal to val(std::remove) or predicate(std::remove_if).
    // If we only call std::remove, will make the vector become { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 } (vector or array size is not changed but shifted)
    //                                                                           ~ returned past-the-end iterator position
    deleteVector.erase(std::remove_if(deleteVector.begin(), 
                                      deleteVector.end(), 
                                      [](int number) { return number < 0; }), // Use returned past-the-end iterator as the begin iterator
                       deleteVector.end());
    std::cout << "deleteVector: " << deleteVector << std::endl;
}