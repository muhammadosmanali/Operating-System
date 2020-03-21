#Tasks:

1. Here, in this lab, you will be carrying out tokenization on strings. Write a piece of code in 
C/C++ that takes an input string from user on command line and then asks for the tokenizer on which the string is to be tokenized. The program then tokenizes the string 
based on the given tokenizer. The input tokenizer can be a white space or any 
alphanumeric character. The output should be in the form of tokens, each on a new line, 
as shown below. 

| Input                                 | Tokenizer | Output                               |
|---------------------------------------|-----------|--------------------------------------|
| She sells sea shells at the seashore. | s         | he_ ell _ ea_ hell _at_the_ ea hore. |
|                                       |           |                                      |

2. After Tokenization, you will be arranging the tokens into ascending order based on their 
first character. For example, special characters such as punctuation marks, white spaces 
are displayed first, then the alphanumeric characters are displayed, digits first, followed 
by the alphabetical display or characters

| Tokenized String                     | Arranged Tokens                      |
|--------------------------------------|--------------------------------------|
| he_ ell _ ea_ hell _at_the_ ea hore. | _ _at_all_ ell ea_ ea he_ hell hore. |
