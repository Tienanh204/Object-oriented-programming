#include"Function.h"
int main() {
     // make sense?
     //Point2D p1;
     //cout << "p1: ";
     //p1.output();
     //cout << endl;

     //Point2D p2; // 0 0
     //cout << "p2: ";
     //p2.output();
     //cout << endl;

     Point2D p3(3, 4); // 3 4
     cout << "p3: ";
     p3.output();
     cout << endl;

     ////Copy
     //Point2D p5(p3); // 3 4
     //cout << "p5: ";
     //p5.output();
     //cout << endl;


     ////Copy=> khong goi constructor
     //Point2D p7 = p3;
     //cout << "p7: ";
     //p7.output();
     //cout << endl;

     ////Gan=> goi constructor
     //Point2D p8;
     //p8 = p3;
     //cout << "p8: ";
     //p8.output();
     //cout << endl;

    cout << "f1(): ";
    f1(p3);
    cout << endl;


    cout << "p14: ";
    Point2D p14;
    p14.output();
    cout << endl;


}




//     // // cout << "f2(): ";
//     // // f2(p3);
//     // // cout << endl;


//     // // cout << "f3(): ";
//     // // f3(&p3);
//     // // cout << endl;


