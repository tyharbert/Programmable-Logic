// Tyler Harbert

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // variables
	string input1, input2;
    int rows, cols;
    
    // getting user input
    cout << endl << "Enter your first binary number:" << endl;
    getline(cin,input1);
    cout << "Enter your second binary number:" << endl;
    getline(cin,input2);
    
    // there are as many rows as the second input length
    rows = input2.length();
    // there are as many cols as the sum of both input lengths
    cols = input1.length() + rows;
    
    // create 2-d array for values to be added
    bool inter_values[rows][cols];
    for(int i = 0 ; i < rows ; i++) {
        // if this rows corresponding value in the second input string is 0, all values are zero
        if(input2[rows-1-i] == '0'){
            for (int j = (cols-1) ; j >= 0 ; j--){
                inter_values[i][j] = false;
            }
        }
        else{
            // insert zeros of the length equal to this row's index
            for (int j = (cols-1) ; j > ((cols-1)-i) ; j--){
                inter_values[i][j] = false;
            }
            // insert the first inputs values
            for (int k = ((cols-1)-i); k > (((cols-1)-i)-input1.length()); k--){
                if(input1[k-(rows-i)] == '0')
                    inter_values[i][k] = false;
                else
                    inter_values[i][k] = true;
            }
            // insert zeros for remaining spaces
            for (int k = (((cols-1)-i)-input1.length()); k >= 0; k--){
                inter_values[i][k] = false;
            }
        }
    }
    
    // set the sum to the first row
    bool sum[cols];
    for (int i=0; i<cols; i++){
        sum[i] = inter_values[0][i];
    }
    // loop through additions
    bool a,b,c;
    for (int i=1; i<rows; i++){
        c = false;
        for (int j=(cols-1); j >= 0 ; j--){
            a = inter_values[i][j];
            b = sum[j];
            // sum logic
            if ((c && ((!a && !b) || (a && b))) || (!c && ((!a && b) || (a && !b)))){
                sum[j] = true;
            }else{
                sum[j] = false;
            }
            
            // carry logic
            if ((a && b) || (c && (a || b))){
                c = true;
            }else{
                c = false;
            }
        }
    }
    
    // print the final product
    cout << "Product:" << endl;
    for (int i=0; i<cols; i++){
        cout << sum[i];
    }
    cout << endl << endl;
    
    return 0;
}