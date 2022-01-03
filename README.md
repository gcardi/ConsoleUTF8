# ConsoleUTF8
UTF8 support for console application (for clang-based compilers)

This small project, which is a small experiment, to come clean, was inspired by an article on a blog that I accidentally read thanks to a link on Codeproject (developer's daily news) mailing list. You can find the article I refer to here: [Some sanity for C and C++ development on Window](https://nullprogram.com/blog/2021/12/30/)

Since I occasionally use Embarcadero's clang-based compilers for non-GUI applications as well, I thought I'd try to see if his solution would work for me too with "my" compilers.

The author of the article (Chris Wellons) argues that the toolchains' C runtime library for Windows does not take into account the fact that most of the legacy code (outside of Windows) uses UTF8. This makes it nearly impossible to easily port applications from Unix / Linux to Windows. [He also has a repository on Github](https://github.com/skeeto/scratch) full of interesting tricks related to console applications on Windows using MinGW. 

Alas, the repository is too big to put in this project as a submodule. So, I took the liberty of copying just a few files from the repository's directory I was interested in (my apologizes in advance).

I "adapted" his technique(s) to Embracadero's clang-based toolchains.

To embed the manifest file (by hand) you need to use the Embarcadero resource compiler (brcc32) like this:

```
brcc32 manifest.rc -iC:\progra~2\Embarcadero\Studio\22.0\include\windows\sdk -iC:\progra~2\Embarcadero\Studio\22.0\include\windows\crtl
```

or, from the IDE, add in the project options (All configurations - All platforms ")

```
-i"$(BDSINCLUDE)\windows\sdk" -i"$(BDSINCLUDE)\windows\crtl"
```

in "Additional Options" in the "Resource Compiler" section.

<a href="https://ibb.co/N6Qq8Xq"><img src="https://i.ibb.co/kgkTRpT/Console-UTF8-1.png" alt="Console-UTF8-1" border="0"></a>

The project embeds the init.c file, the utf8.xml file, and the manifest.rc file taken from the above repository. I simply created a Console Application and modified the main body with the code taken from the main body of the above repository example.

It just works:

<a href="https://ibb.co/DWm5BR7"><img src="https://i.ibb.co/YQJp5Lt/Console-UTF8-2.png" alt="Console-UTF8-2" border="0"></a>
