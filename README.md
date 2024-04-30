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
        reroll i – 1 ?  
    ><

    reroll nat kobold j 5 ?  
    dungeon j floors <>  
        quest j CD 2 //  
            say *smol* ?  
        \\  
        railroad //  
            say *beeg* ?  
        \\  
        reroll j – 1 ?  
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

### Syntax
| Keyword    | Description                      |
|------------|----------------------------------|
| roll       | Define an object or function     |
| initiative | main function                    |
| reroll     | Declare or manipulate a variable |
| nat        | Declare a new variable           |
| quest      | If statement                     |
| sidequest  | Else If statement                |
| railroad   | Else statement                   |
| dungeon    | Define loop                      |
| floors     | Number of times to run loop      |
| say        | Print to screen                  |


### Syntax Rules  

- All lines end with the `?` character.  
- Single line comments begin with `_^`.
- Multi-line comments begin and end with `||`.
- Blocks of code in a `quest` statement begin with `//` and end with `\\`. All other blocks of code begin with `<>` and end with `><`.  
- Strings begin and end with the `*` character.  
- All lines involving the creation or manipulation of variables begin with the keyword `reroll`. The keyword `nat` is used to define a new variable.
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

Write a dandd file in the same folder where the C++ code is, name the file MainDungeon.dandd, run the C++ code 

### Valid Grammars

`reroll nat [varType] [varName] [value] ?`  
`reroll [varName] [mathOperator] [number] ?`  
`say *[stringValue]* ?`  
`say [varName] ?`  
`say [number] ?`  
`dungeon [number] floors <>`  
`dungeon [numericalVarName] floors <>`  
`_^ [comment text]`  
`|| [comment text] ||`

### Language State