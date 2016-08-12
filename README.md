# leetcode

#Palindrome.c
在Palindrome.c中，s[End + 1] = 0;这一句在codelock（gcc）和inux下gcc编译都会提示错误！Windows下返回SIGSEGV，Linux下返回Segmentation fault (core dumped)。但是提交到leetcode中为出现错误提示。
