
## Description

Santa is trying to deliver presents in a large apartment building, but he can't find the right floor - the directions he got are a little confusing. He starts on the ground floor `(floor 0)` and then follows the instructions one character at a time.

An opening parenthesis, `(`, means he should go `up one floor`, and a closing parenthesis, `)`, means he should go `down one floor`.

The apartment building is very tall, and the basement is very deep; he will never find the top or bottom floors.

For example:

- `(())` and `()()` both result in floor 0.
- `(((` and `(()(()(` both result in floor 3.
- `))(((((` also results in floor 3.
- `())` and `))(` both result in floor -1 (the first basement level).
- `)))` and `)())())` both result in floor -3.

Santa get's the instructions from a `TCP` server. The host is `20.108.244.219` on port `9990`
>> the instructions are terminated with a new line character `\n` character for example 

```
$ nc 20.110.238.2 9990
)())())

```

He then has `15` seconds(yep including latency!) to reply with the correct floor or the server will terminate the connection.
```bash
$ nc 20.110.238.2 9990
(()())))(())()))())(()())(()((()((((((())())

Too slow!!
```

On your reply the server sends an approriate message and terminate the connection

```
$ nc 20.110.238.2 9990
)))())(((())()()(()(())(())()))(
-2
Right! ans=-2

$ nc 20.110.238.2 9990
))()((((()((()())(()))))((()(()(((())(()()())())))))))))()))()))
0
Wrong! ans=-8
```

Your task is to write Santa a C/Cpp program that gets him the instructions from the TCP server, calculates the right floor and sends it to the server for validation.

The puzzles are randomly generated each time so the solution is not constant.

### Submission

>> Time: 45 mins

Send the link to your public repository containing your work via email.

If you are unable to use version control, you can put your work in a compressed folder and attach it to your email, note use of version control is also assessed.

>> Include a document with instruction on how to compile and run your solution.