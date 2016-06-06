# Code-Formatter

This c++ program takes program source code as input and outputs the same code, nicely formatted for readability.

The great thing is, this program is language independent; so, it works on any and every language (keeping in mind most of the common indentation rules like spacing and nesting).

For example if you are typing in C++, this program will indent and format everything properly with one space in place of multiple spaces that your input source code may have but if there are similar multiple spaces after the "//" sign, then that is not formatted because that signifies the start of a comment.

This is a smart formatter which uses the following approach:
• Initially, the code is flush to the left margin (i.e., not indented)
• If the word is ;, the word is printed and this program moves on to the next line
• If the word is {, the word is printed, the program moves to the next line, and the following lines are indented by one more   space than previously according to the desirable format.
• If the word is }, it is be printed on its own line, indented one character to the left of the lines between it and its      matching { (i.e., the indentation level will be the same as the indentation level of the line that contained the matching {), and the following lines are indented to the same level as this word;
• If the word is //, then the rest of the current line of input is considered a comment, and is be printed exactly as it is, including spacing;
• Except for comments, all of the tokens on a line are separated from one another by exactly one space.

This program works best for C-like code but works on all language code inputs.

Sample input:

int f ( int x ) { // This is my function
inty=x;y=y+1;returny;} //Thisisthe END ofmyfunction int main () { int n = 0 ; while ( n < 10 ) { n = f ( n ) ; } }


Corresponding output:
<PRE>
int f ( int x ) {
// This is my function int y = x ; y=y+1;
return y ;
}
// Thisisthe END ofmyfunction
int main () {
 int n = 0 ;
 while ( n < 10 ) {
    n=f(n);
  }
}
