#include <string>
#include <set>
#include <iostream>

class MVN{
    private:
        std::set<double> possibilities;
        MVN(){}
    public:
        // Constructor
        MVN(std::set<double> p){
            possibilities = p;
        }

        // Operators
        void operator = (MVN const &obj){
            possibilities = obj.possibilities;
        }

        MVN operator + (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 + p2);
                }
            }
            return result;
        }

        MVN operator += (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 + p2);
                }
            }
            *this = result;
            return *this;
        }

        MVN operator - (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 - p2);
                }
            }
            return result;
        }
        
        MVN operator -= (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 - p2);
                }
            }
            *this = result;
            return *this;
        }

        MVN operator * (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 * p2);
                }
            }
            return result;
        }
        
        MVN operator *= (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 * p2);
                }
            }
            *this = result;
            return *this;
        }

        MVN operator / (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 / p2);
                }
            }
            return result;
        }
        
        MVN operator /= (MVN const &obj){
            MVN result;
            for (auto p1 : possibilities){
                for (auto p2 : obj.possibilities){
                    result.possibilities.insert(p1 / p2);
                }
            }
            *this = result;
            return *this;
        }

        // Utility functions
        std::string to_string(){
            std::string output = "[";
            for (auto possibility: possibilities){
                output += std::to_string(possibility) + ", ";
            }
            return output.substr(0, output.size()-2) + "]R";
        }

        size_t degree(){
            return possibilities.size();
        }

        // Special MVNs
        static MVN basis(int n){
            std::set<double> s;
            for (int i = 0; i <= n; i++){
                s.insert(i);
            }
            return MVN{s};
        }
};

int main(){
    MVN m = MVN::basis(1);
    m += m;
    std::cout << m.to_string() << "  :  " << m.degree() << '\n';
}