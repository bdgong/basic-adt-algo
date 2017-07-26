/*
 * Huffman tree and Huffman encoding.
 * !g++ % -o %< -std=c++11 -g 
 * */
#include "HuffmanTree.hpp"

int main()
{
    using namespace bdgong;
    using namespace std;
    CHuffmanTree ht;
    std::vector<char> vals = {'A', 'B', 'C', 'D'};
    std::vector<int> weights = {4, 3, 2, 1};
    std::vector<string> codings = ht.getCoding(vals, weights);
    auto posVal = vals.cbegin();
    for_each(codings.cbegin(), codings.cend(), [&](const string& s){
                cout << *posVal << " " << s << endl;
                ++posVal;
            });
    return 0;
}
