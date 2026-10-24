# Chisel Documentation

Chisel aims to be a simple code formatting tool.  Although it is primarily design to format **Lua**
code, it aims to become general enough to format any other language if a syntax and a set of rules
are provided.

This document is a language agnostic description of the problem and the proposed solution(s) to be
implemented in any programming language.


# The problem

We want to apply some formatting rules to some source code in some programming language.  Possible
scenarios are:

- Read a file and write formatted output to a file (possibly the same file).
- Read a string and give back a new string with the formatted output.

In both cases, the logic remains the same:

**INPUT**: string containing the source code.

**OUTPUT**: new string with the formatted source code.

Even if we want to _read from file_ and optionally _write to file_ or _read from stdin_ and output
to _stdout_, eventually we'll get a string and give back a string.  The _reading_ and _writing_ part
just surrounds our main algorithm.


## Knowing more about the problem

Formatting is basically just adding, removing or changing white space.  By the most part _space_ "\\
", _tabs_ "\\t" and _line feed_ "\\n" (sometimes referred to as "newline" character).  Although
other white space characters do exist, I have never encountered them in source code.

Anyway, for the purpose of solving this particular problem, I think we'll manage with those.

So, we need a way to read the text and know where to put, remove or replace white space.  To begin
with, we'll need two things:

- A way to identify individual "atoms" in the source code and know their semantics.
- A set of rules for placing white space around those "atoms".

An "atom" is a string of characters that can not be decomposed any further.  I.e, in **Lua** "local"
is an _atom_ but "table.insert" is not.  "a + b" (or "a+b") is composed of three _atoms_: "a", "+"
and "b" and "table.insert" is also made up from three _atoms_: "table", "." and "insert" (a _name_,
an _operator_ and a _field/method_ in this case).

In Computer Science and programming is common to call this "atoms" _tokens_, so I'll follow that
convention from now on.
