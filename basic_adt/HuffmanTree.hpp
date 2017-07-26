#include <iostream>
#include <vector>
#include <algorithm>

namespace bdgong
{
    const int cInvalid = -1;
    /*
     * Default coding for char.
     * */
    class CHuffmanTree
    {
        public:
            CHuffmanTree() {
            }
            ~CHuffmanTree() {
            }
            void create(std::vector<char> &vals, std::vector<int> &weights) {
                // set the initial values
                int size = vals.size();
                nodes.resize(2 * size);

                int index;
                for(index=0; index<size ; ++index) {
                    Node node{vals.at(index), weights.at(index), cInvalid, cInvalid, cInvalid};
                    nodes[index] = node;
                }

                // do create operation
                for(index=size; index < 2*size-1 ; ++index) {
                    std::pair<int, int> mm = selectTwoMinWeight(index);
                    int min1Index = mm.first;
                    int min2Index = mm.second;

                    Node parent;
                    parent.iParent = cInvalid;
                    parent.iL = min1Index;
                    parent.iR = min2Index;
                    parent.weight = nodes[min1Index].weight + nodes[min2Index].weight;
                    nodes[min1Index].iParent = nodes[min2Index].iParent = index;

                    nodes[index] = parent;
                }
            }

            /*
             * @return A pair contains two index of minimum weight node in nodes.  The first <= second.
             * */
            std::pair<int, int> selectTwoMinWeight(int lastIndex) {
                int min1Index = lastIndex, min2Index = lastIndex;       // assume min1Index <= min2Index
                for(int i=0; i<lastIndex ; ++i) {
                    Node node = nodes.at(i);
                    if(node.iParent == cInvalid) {
                        if(min1Index == lastIndex || node.weight < nodes.at(min1Index).weight) {
                            min2Index = min1Index;
                            min1Index = i;
                        }
                        else if(min2Index == lastIndex || node.weight < nodes.at(min2Index).weight) {
                            min2Index = i;
                        }
                        else {}
                    }
                    else {}
                }
                return std::make_pair(min1Index, min2Index);
            }

            std::vector<std::string> encoding(std::vector<char> &vals) {
                int size = vals.size();
                std::vector<std::string> codings(size);
                for(int i=0; i<size ; ++i) {
                    int iNext = i;
                    int iParent = nodes[iNext].iParent; 
                    while(iParent != cInvalid) {
                        if(nodes[iParent].iL == iNext) {
                            codings[i].append("0");
                        }
                        else {
                            codings[i].append("1");
                        }

                        iNext = iParent;
                        iParent = nodes[iNext].iParent;
                    }
                    std::reverse(codings[i].begin(), codings[i].end());
                }
                return codings;
            } 
            std::vector<std::string> getCoding(std::vector<char> &vals, 
                    std::vector<int> &weights) {
                create(vals, weights);

                //std::for_each(nodes.cbegin(), nodes.cend(), [](const Node& node){
                            //std::cout << node.val << " "
                                //<< node.weight << " "
                                //<< node.iParent << " " << node.iL << " " << node.iR
                                //<< std::endl;
                        //});

                return encoding(vals);
            }
        private:
            typedef struct node {
                char val;
                int weight;
                int iParent, iL, iR;
            }Node;

            std::vector<Node> nodes;
    };
}

