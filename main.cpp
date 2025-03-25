#include <iostream>
#include <fstream>

using namespace std;

/* explain the attribute
 * ---------------------
 * 1- getOrder -> to get the order_size of the polynomial
 * 2- getCoefficient -> to get the coefficient of this polynomial
 * 3- print_poly -> to print_poly the polynomial
 * 4- operator overload on + -> to add two polynomial and return the result as string
 * 5- operator overload on - -> to s two polynomial and return the result as string
 * */

class polynomial {
protected:
    int order_size;
    int *coeff_array;
    string poly;
    int *sum_coeff;
    int *diff_coeff;

    string get_poly(int *arr, int size, char c) {
        string s;
        if (c == '+') {
            for (int i = size - 1; i >= 0; i--) {
                int Power = i - 1;
                if (Power == -1) {
                    s += " = ";
                    if (arr[i] >= 0) {
                        s += to_string(arr[i]);
                    } else {
                        s += " - " + to_string(-arr[i]);
                    }
                } else if (Power == 0) {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            s += " + " + to_string(arr[i]);
                        } else {
                            s += " - " + to_string(-arr[i]);
                        }
                    }
                } else if (Power == 1) {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            s += " + ";
                            if (arr[i] != 1) s += to_string(arr[i]);
                            s += "X";
                        } else {
                            s += " - ";
                            if (arr[i] != 1) s += to_string(-arr[i]);
                            s += "X";
                        }
                    }
                } else {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            if (i != size - 1) s += " + ";
                            if (arr[i] != 1) s += to_string(arr[i]);
                            s += "X^" + to_string(Power);
                        } else {
                            s += " - ";
                            if (arr[i] != 1) s += to_string(-arr[i]);
                            s += "X^" + to_string(Power);
                        }
                    }
                }
            }

        } else {
            for (int i = size - 1; i >= 0; i--) {
                int Power = i - 1;
                if (Power == -1) {
                    s += " = ";
                    if (arr[i] >= 0) {
                        s += to_string(arr[i]);
                    } else {
                        s += " - " + to_string(-arr[i]);
                    }
                } else if (Power == 0) {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            s += " + " + to_string(arr[i]);
                        } else {
                            s += " - " + to_string(-arr[i]);
                        }
                    }
                } else if (Power == 1) {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            s += " + ";
                            if (arr[i] != 1) s += to_string(arr[i]);
                            s += "X";
                        } else {
                            s += " - ";
                            if (arr[i] != -1) s += to_string(-arr[i]);
                            s += "X";
                        }
                    }
                } else {
                    if (arr[i] != 0) {
                        if (arr[i] > 0) {
                            if (i != size - 1) s += " + ";
                            if (arr[i] != 1) s += to_string(arr[i]);
                            s += "X^" + to_string(Power);
                        } else {
                            s += " - ";
                            if (arr[i] != -1) s += to_string(-arr[i]);
                            s += "X^" + to_string(Power);
                        }
                    }
                }
            }
        }
        return s;
    }

    void set_size(int n) {
        order_size = n + 2;
        coeff_array = new int[order_size];
    }

public:
    polynomial() {
        order_size = 0;
        coeff_array = nullptr;
        sum_coeff = nullptr;
        diff_coeff = nullptr;
    }

    virtual void get_order() = 0;

    virtual void getCoefficient() = 0;

    void print_poly() {
        for (int i = order_size - 1; i >= 0; i--) {
            int Power = i - 1;
            if (Power == -1) {
                poly += " = ";
                if (coeff_array[i] >= 0) {
                    poly += (char) (coeff_array[i] + '0');
                } else {
                    int ch = coeff_array[i];
                    ch *= -1;
                    poly += " -";
                    poly += (char) (coeff_array[i] + '0');
                }
            } else if (Power == 0) {
                if (coeff_array[i] != 0) {
                    if (coeff_array[i] > 0) {
                        poly += " + ";
                        poly += (char) (coeff_array[i] + '0');
                    } else {
                        int ch = coeff_array[i];
                        ch *= -1;
                        poly += " - ";
                        poly += (char) (coeff_array[i] + '0');
                    }
                }
            } else if (Power == 1) {
                if (coeff_array[i] != 0) {
                    if (coeff_array[i] > 0) {
                        poly += " + ";
                        if (coeff_array[i] != 1) poly += (char) (coeff_array[i] + '0');

                        poly += 'X';
                    } else {
                        int ch = coeff_array[i];
                        ch *= -1;
                        poly += " - ";
                        if (coeff_array[i] != 1) poly += (char) (coeff_array[i] + '0');
                        poly += 'X';
                    }
                }
            } else {
                if (coeff_array[i] != 0) {
                    if (coeff_array[i] >= 0) {
                        if (i != order_size - 1)poly += " + ";
                        if (coeff_array[i] != 1) poly += (char) (coeff_array[i] + '0');
                        poly += "X^";
                        poly += (char) (Power + '0');

                    } else {
                        int ch = coeff_array[i];
                        ch *= -1;
                        poly += " - ";
                        if (coeff_array[i] != 1) poly += (char) (coeff_array[i] + '0');
                        poly += "X^";
                        poly += (char) (Power + '0');
                    }
                }
            }
        }
        cout << poly << endl;
    }

    string operator+(const polynomial &p2) {

        int max_size = max(order_size, p2.order_size);
        int min_size = min(order_size, p2.order_size);


        sum_coeff = new int[max_size];

        for (int i = 0; i < min_size; i++) {
            sum_coeff[i] = coeff_array[i] + p2.coeff_array[i];
        }
        for (int i = min_size; i < max_size; i++) {
            sum_coeff[i] = (order_size > p2.order_size) ? coeff_array[i] : p2.coeff_array[i];
        }
        return get_poly(sum_coeff, max_size, '+');
    }

    string operator-(const polynomial &p2) {

        int max_size = max(order_size, p2.order_size);
        int min_size = min(order_size, p2.order_size);

        diff_coeff = new int[max_size];

        for (int i = 0; i < min_size; i++) {
            diff_coeff[i] = coeff_array[i] - p2.coeff_array[i];
        }
        for (int i = min_size; i < max_size; i++) {
            diff_coeff[i] = (order_size > p2.order_size) ? coeff_array[i] : p2.coeff_array[i];
        }

        return get_poly(diff_coeff, max_size, '-');
    }

    void Delete() {
        delete[] coeff_array;
        delete[] sum_coeff;
        delete[] diff_coeff;
        order_size = 0;
        coeff_array = nullptr;
        sum_coeff = nullptr;
        diff_coeff = nullptr;
    }

    ~polynomial() {
        delete[] coeff_array;
        delete[] sum_coeff;
        delete[] diff_coeff;
    }

};

class terminal_poly : public polynomial {
public:
    void get_order() override {
        int n;
        cin >> n;
        set_size(n);
    }

    void getCoefficient() {
        for (int i = 0; i < order_size; i++) {
            cin >> coeff_array[i];
        }
    }
};


class file_poly : public polynomial {
private:
    string name;
    ifstream file;
public:
    file_poly(string s) : name(s) {
        file.open(name + ".txt");
        if (!file.is_open()) { throw runtime_error("Error: File not found!"); }
    }

    void get_order() override {


        int n;
        file >> n;
        set_size(n);

    }

    void getCoefficient() {

        for (int i = 0; i < order_size; i++) {
            file >> coeff_array[i];
        }
    }

    ~file_poly() {
        if (file.is_open()) file.close();
    }
};


int main() {
    int choice;

    cout << "Choose input method:\n1. Terminal\n2. File\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            polynomial *p1 = new terminal_poly;
            polynomial *p2 = new terminal_poly;
            int n;
            cout << "order_size of first polynomial: \n";
            p1->get_order();

            cout << "Enter polynomial: \n";

            p1->getCoefficient();

            cout << "order_size of second polynomial: \n";

            p2->get_order();

            cout << "Enter polynomial: \n";
            p2->getCoefficient();

            cout << "First polynomial: ";
            p1->print_poly();

            cout << "Second polynomial: ";
            p2->print_poly();

            string add = (*p1) + (*p2);
            cout << "Sum of polynomials: " << add << endl;
            string s = (*p2) - (*p1);
            cout << "Difference of polynomials: " << s << endl;

            delete p1;
            delete p2;
            break;
        }
        case 2:

            int tx = 3;
            int count = 0;
            while (tx--) {
                string name = "test";
                if (count > 0) {
                    name += to_string(count);
                }
                count++;

                polynomial *p1 = new file_poly(name);
                name = name + 'p';
                polynomial *p2 = new file_poly(name);
                p1->get_order();

                p1->getCoefficient();

                p2->get_order();

                p2->getCoefficient();

                cout << "First polynomial: ";
                p1->print_poly();

                cout << "Second polynomial: ";
                p2->print_poly();

                string add = (*p1) + (*p2);
                cout << "Sum of polynomials: " << add << endl;
                string s = (*p2) - (*p1);
                cout << "Difference of polynomials: " << s << endl;
                cout << "----------------------------" << endl << endl;

                delete p1;
                delete p2;
            }

            break;
    }

}




//#include <iostream>
//
//using namespace std;
//
///* explain the attribute
// * ---------------------
// * 1- getOrder -> to get the order of the polynomial
// * 2- getCoefficient -> to get the coefficient of this polynomial
// * 3- print -> to print the polynomial
// * 4- operator overload on + -> to add two polynomial and return the result as string
// * 5- operator overload on - -> to subtract two polynomial and return the result as string
// * */
//
//
//class polynomial {
//private:
//    int order;
//    int *poly;
//    string Polynomial;
//
//public:
//    polynomial() {
//        order = 0;
//        poly = nullptr;
//    }
//
//    void getOrder(int n) {
//        order = n + 2;
//        poly = new int[order];
//    }
//
//    void getCoefficient() {
//        for (int i = 0; i < order; i++) {
//            cin >> poly[i];
//        }
//    }
//
//    void print() {
//
//        for (int i = order - 1; i >= 0; i--) {
//            int Power = i - 1;
//            if (Power == -1) {
//                Polynomial += " = ";
//                if (poly[i] >= 0) {
//                    Polynomial += (char) (poly[i] + '0');
//                } else {
//                    int ch = poly[i];
//                    ch *= -1;
//                    Polynomial += " -";
//                    Polynomial += (char) (poly[i] + '0');
//                }
//            } else if (Power == 0) {
//                if (poly[i] != 0) {
//                    if (poly[i] > 0) {
//                        Polynomial += " + ";
//                        Polynomial += (char) (poly[i] + '0');
//                    } else {
//                        int ch = poly[i];
//                        ch *= -1;
//                        Polynomial += " - ";
//                        Polynomial += (char) (poly[i] + '0');
//                    }
//                }
//            } else if (Power == 1) {
//                if (poly[i] != 0) {
//                    if (poly[i] > 0) {
//                        Polynomial += " + ";
//                        if (poly[i] != 1) Polynomial += (char) (poly[i] + '0');
//
//                        Polynomial += 'X';
//                    } else {
//                        int ch = poly[i];
//                        ch *= -1;
//                        Polynomial += " - ";
//                        if (poly[i] != 1) Polynomial += (char) (poly[i] + '0');
//                        Polynomial += 'X';
//                    }
//                }
//            } else {
//                if (poly[i] != 0) {
//                    if (poly[i] >= 0) {
//                        if (i != order - 1)Polynomial += " + ";
//                        if (poly[i] != 1) Polynomial += (char) (poly[i] + '0');
//                        Polynomial += "X^";
//                        Polynomial += (char) (Power + '0');
//
//                    } else {
//                        int ch = poly[i];
//                        ch *= -1;
//                        Polynomial += " - ";
//                        if (poly[i] != 1) Polynomial += (char) (poly[i] + '0');
//                        Polynomial += "X^";
//                        Polynomial += (char) (Power + '0');
//                    }
//                }
//            }
//        }
//        cout << Polynomial << endl;
//    }
//
//    string operator+(const polynomial &poly2) {
//        string add;
//        if (order >= poly2.order) {
//
//            int *newsecondPolynomial = new int[order];
//
//
//            for (int i = 0; i < poly2.order; i++) {
//                newsecondPolynomial[i] = poly2.poly[i];
//            }
//            for (int i = poly2.order; i < order; i++) {
//                newsecondPolynomial[i] = 0;
//            }
//
//            //  the sum
//            int *sum = new int[order];
//
//            for (int i = 0; i < order; i++) {
//                sum[i] = poly[i] + newsecondPolynomial[i];
//            }
//
//            //  the sum
//            for (int i = order - 1; i >= 0; i--) {
//                int Power = i - 1;
//                if (Power == -1) {
//                    add += " = ";
//                    if (sum[i] >= 0) {
//                        add += to_string(sum[i]);
//                    } else {
//                        add += " - " + to_string(-sum[i]);
//                    }
//                } else if (Power == 0) {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            add += " + " + to_string(sum[i]);
//                        } else {
//                            add += " - " + to_string(-sum[i]);
//                        }
//                    }
//                } else if (Power == 1) {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            add += " + ";
//                            if (poly[i] != 1) add += to_string(sum[i]);
//                            add += "X";
//                        } else {
//                            add += " - ";
//                            if (poly[i] != 1) add += to_string(-sum[i]);
//                            add += "X";
//                        }
//                    }
//                } else {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            if (i != order - 1) add += " + ";
//                            if (poly[i] != 1) add += to_string(sum[i]);
//                            add += "X^" + to_string(Power);
//                        } else {
//                            add += " - ";
//                            if (poly[i] != 1) add += to_string(-sum[i]);
//                            add += "X^" + to_string(Power);
//                        }
//                    }
//                }
//            }
//            delete[] sum;
//            delete[] newsecondPolynomial;
//        } else {
//
//            int *newpoly = new int[poly2.order];
//
//            for (int i = 0; i < order; i++) {
//                newpoly[i] = poly[i];
//            }
//            for (int i = order; i < poly2.order; i++) {
//                newpoly[i] = 0;
//            }
//
//            int *sum = new int[poly2.order];
//
//            for (int i = 0; i < poly2.order; i++) {
//                sum[i] = poly2.poly[i] + newpoly[i];
//
//            }
//
//            // the sum
//            for (int i = poly2.order - 1; i >= 0; i--) {
//                int Power = i - 1;
//                if (Power == -1) {
//                    add += " = ";
//                    if (sum[i] >= 0) {
//                        add += to_string(sum[i]);
//                    } else {
//                        add += " - " + to_string(-sum[i]);
//                    }
//                } else if (Power == 0) {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            add += " + " + to_string(sum[i]);
//                        } else {
//                            add += " - " + to_string(-sum[i]);
//                        }
//                    }
//                } else if (Power == 1) {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            add += " + ";
//                            if (sum[i] != 1) { add += to_string(sum[i]); }
//                            add += "X";
//                        } else {
//                            add += " - ";
//                            if (sum[i] != 1) { add += to_string(-sum[i]); }
//                            add += "X";
//                        }
//                    }
//                } else {
//                    if (sum[i] != 0) {
//                        if (sum[i] > 0) {
//                            if (i != poly2.order - 1) add += " + ";
//                            if (sum[i] != 1) { add += to_string(sum[i]); }
//                            add += "X^" + to_string(Power);
//                        } else {
//                            add += " - ";
//                            if (sum[i] != 1) { add += to_string(-sum[i]); }
//                            add += "X^" + to_string(Power);
//                        }
//                    }
//                }
//            }
//            delete[] sum;
//            delete[] newpoly;
//
//        }
//        return add;
//    }
//
//    string operator-(const polynomial &poly2) {
//        string subtract;
//        if (order >= poly2.order) {
//            int *newsecondPolynomial = new int[order];
//
//            for (int i = 0; i < poly2.order; i++) {
//                newsecondPolynomial[i] = poly2.poly[i];
//            }
//            for (int i = poly2.order; i < order; i++) {
//                newsecondPolynomial[i] = 0;
//            }
//
//            // the difference
//            int *diff = new int[order];
//            for (int i = 0; i < order; i++) {
//                diff[i] = poly[i] -  newsecondPolynomial[i];
//            }
//
//            for (int i = order - 1; i >= 0; i--) {
//                int Power = i - 1;
//                if (Power == -1) {
//                    subtract += " = ";
//                    if (diff[i] >= 0) {
//                        subtract += to_string(diff[i]);
//                    } else {
//                        subtract += " - " + to_string(-diff[i]);
//                    }
//                } else if (Power == 0) {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            subtract += " + " + to_string(diff[i]);
//                        } else {
//                            subtract += " - " + to_string(-diff[i]);
//                        }
//                    }
//                } else if (Power == 1) {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            subtract += " + ";
//                            if (diff[i] != 1) subtract += to_string(diff[i]);
//                            subtract += "X";
//                        } else {
//                            subtract += " - ";
//                            if (diff[i] != -1) subtract += to_string(-diff[i]);
//                            subtract += "X";
//                        }
//                    }
//                } else {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            if (i != order - 1) subtract += " + ";
//                            if (diff[i] != 1) subtract += to_string(diff[i]);
//                            subtract += "X^" + to_string(Power);
//                        } else {
//                            subtract += " - ";
//                            if (diff[i] != -1) subtract += to_string(-diff[i]);
//                            subtract += "X^" + to_string(Power);
//                        }
//                    }
//                }
//            }
//
//            delete[] newsecondPolynomial;
//            delete[] diff;
//        } else {
//            int *newpoly = new int[poly2.order];
//
//            for (int i = 0; i < order; i++) {
//                newpoly[i] = poly[i];
//            }
//            for (int i = order; i < poly2.order; i++) {
//                newpoly[i] = 0;
//            }
//
//            int *diff = new int[poly2.order];
//            for (int i = 0; i < poly2.order; i++) {
//                diff[i] = newpoly[i] -  poly2.poly[i] ;
//            }
//
//            //  the difference
//            for (int i = poly2.order - 1; i >= 0; i--) {
//                int Power = i - 1;
//                if (Power == -1) {
//                    subtract += " = ";
//                    if (diff[i] >= 0) {
//                        subtract += to_string(diff[i]);
//                    } else {
//                        subtract += " - " + to_string(-diff[i]);
//                    }
//                } else if (Power == 0) {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            subtract += " + " + to_string(diff[i]);
//                        } else {
//                            subtract += " - " + to_string(-diff[i]);
//                        }
//                    }
//                } else if (Power == 1) {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            subtract += " + ";
//                            if (diff[i] != 1) subtract += to_string(diff[i]);
//                            subtract += "X";
//                        } else {
//                            subtract += " - ";
//                            if (diff[i] != -1) subtract += to_string(-diff[i]);
//                            subtract += "X";
//                        }
//                    }
//                } else {
//                    if (diff[i] != 0) {
//                        if (diff[i] > 0) {
//                            if (i != poly2.order - 1) subtract += " + ";
//                            if (diff[i] != 1) subtract += to_string(diff[i]);
//                            subtract += "X^" + to_string(Power);
//                        } else {
//                            subtract += " - ";
//                            if (diff[i] != -1) subtract += to_string(-diff[i]);
//                            subtract += "X^" + to_string(Power);
//                        }
//                    }
//                }
//            }
//
//            delete[] newpoly;
//            delete[] diff;
//        }
//        return subtract;
//    }
//
//    ~polynomial() {
//        delete[] poly;
//    }
//
//};
//
//
//int main() {
//
//    polynomial p1;
//    polynomial p2;
//    int n;
//    cout << "Order of first polynomial: \n";
//    cin >> n;
//    p1.getOrder(n);
//
//    cout << "Enter polynomial: \n";
//
//    p1.getCoefficient();
//
//    cout << "Order of second polynomial: \n";
//    cin >> n;
//    p2.getOrder(n);
//
//    cout << "Enter polynomial: \n";
//    p2.getCoefficient();
//
//    cout << "First polynomial: ";
//    p1.print();
//
//    cout << "Second polynomial: ";
//    p2.print();
//
//    string add = p1 + p2;
//    cout << "Sum of polynomials: " << add << endl;
//    string subtract = p2 - p1;
//    cout << "Difference of polynomials: " << subtract << endl;
//
//}