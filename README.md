# Data And Developers

#### A Programming Language by Nathaniel Lofgren, Tala Garibay, and Isaac Stiles    

![Data and Developers Logo](/img/Data%20&%20Developers.jpg)

### Overview  

Data and Developers is a programming language based on Dungeons and Dragons. It is a statically-typed interpreted language built on C++. Data and Developers files have a file extension of .dandd.  

### Demo Code

##### Code:
```
roll initiative <>

    nat Gary kobold 5 ?  
    nat dragon Bob *Hello World* ?

    dungeon 3 floors <>  
        say Bob ?  
    ><

    nat i kobold 4 ?  
    dungeon i floors <>  
        quest i is 3 //  
            say *Woo* ?  
        \\  
        railroad //  
            say *no woo* ?
        \\  
        reroll kobold i – 1 ?  
    ><

    nat j kobold 5 ?  
    dungeon j floors <>  
        quest j CD 2 //  
            say *smol* ?  
        \\  
        railroad //  
            say *beeg* ?  
        \\  
        reroll kobold j – 1 ?  
    ><  
><  
```
##### Output:
>Hello World  
no woo  
Woo  
no woo  
no woo  
beeg  
beeg  
beeg  
smol  
smol  

### Reserved Words
| Keyword    | Description                  |
|------------|------------------------------|
| roll       | Define an object or function |
| initiative | main function                |
| nat        | Declare a new variable       |
| reroll     | Manipulate a variable        |
| quest      | If statement                 |
| sidequest  | Else If statement            |
| railroad   | Else statement               |
| dungeon    | Define loop                  |
| floors     | Number of times to run loop  |
| say        | Print to screen              |


### Syntax Rules  

- All lines end with the `?` character.  
- Single line comments begin with `_^`.
- Multi-line comments begin and end with `||`.
- Blocks of code in a `quest` statement begin with `//` and end with `\\`. All other blocks of code begin with `<>` and end with `><`.  
- Strings begin and end with the `*` character.  
- All lines involving the manipulation of variables begin with the keyword `reroll`. A variable's type must always be passed into the `reroll` statement.  
- If a `dungeon` statement is passed a number in its header, it will loop a fixed number of times. If it is passed a variable with a numeric value, it will loop until the variable's value is as specified in the header.

### Binary Operators
| DandD Binary Operator | C++ Binary Operator | Operation                |
|-----------------------|---------------------|--------------------------|
| &                     | +                   | Addition                 |
| –                     | -                   | Subtraction              |
| ·                     | *                   | Multiplication           |
| ÷                     | /                   | Division                 |
| is                    | ==                  | Equality Comparison      |
| AC                    | \>                  | Greater Than             |
| DC                    | \>=                 | Greater Than or Equal To |
| CA                    | <                   | Less Than                |
| CD                    | <=                  | Less Than or Equal To    |

### Variable Types  

| DandD Variable Type | C++ Variable Type |
|---------------------|-------------------|
| goblin              | bool              |  
| kobold              | int               |  
| dragon              | string            |  

### How to Run

- Download BaseCode.cpp from the repository
- Name the file with the DandD program MainDungeon.dandd 
- Save MainDungeon.dandd to the same folder as BaseCode.cpp
- Run BaseCode.cpp in a C++ environment (such as JetBrains CLion)

### Valid Grammars

1. `nat [varType] [varName] [value] ?`  
2. `reroll [varType] [varName] [mathOperator] [number] ?`  
3. `reroll [varType] [varName] [number] ?`  
4. `say *[stringValue]* ?`  
5. `say [varName] ?`  
6. `say [number] ?`  
7. `dungeon [number] floors <>`  
8. `dungeon [numericalVarName] floors <>`  
9. `_^ [comment text]`  
10. `|| [comment text] ||`

### Language State
- Only Print, basic Operations, and Variable Declaration currently work
- Creates a tree based off of the token structure
- Current valid grammer statements are 1 - 6 and 9
- Throws some errors if grammar is off, like if variable type is not valid
- Two lines can't say the same thing in a row b/c the last line was repeating so this was the fix
- Variables only recognize the last operation made to them and don't store that information
- Recognizes any amount of binary operations and does them from left to right 
