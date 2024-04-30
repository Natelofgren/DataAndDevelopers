# Data And Developers

#### A Programming Language by Nathaniel Lofgren, Tala Garibay, and Isaac Stiles    

### Overview  

Data and Developers is a programming language based on Dungeons and Dragons. It is a statically-typed interpreted language built on C++. Data and Developers files have a file extension of .dandd.  

### Demo Code

##### Code:
```
roll initiative <>

    reroll nat kobold Gary 5 ?  
    reroll nat dragon Bob *Hello World* ?

    dungeon 3 floors <>  
        say Bob ?  
    ><

    reroll nat kobold i 4 ?  
    dungeon i floors <>  
        quest i is 3 //  
            say *Woo* ?  
        \\  
        railroad //  
            say *no woo* ?
        \\  
        reroll kobold i – 1 ?  
    ><

    reroll nat kobold j 5 ?  
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

`nat [varType] [varName] [value] ?`  
`reroll kobold [varName] [mathOperator] [number] ?`  
`reroll kobold [varName] [number] ?`  
`say *[stringValue]* ?`  
`say [varName] ?`  
`say [number] ?`  
`dungeon [number] floors <>`  
`dungeon [numericalVarName] floors <>`  
`_^ [comment text]`  
`|| [comment text] ||`

### Language State
- Two lines can't say the same thing b/c the last line was repeating so this was the fix