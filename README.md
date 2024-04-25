# Data And Developers

#### A Programming Language by Nathaniel Lofgren, Tala Garibay, and Isaac Stiles    

### Overview  

Data and Developers is a programming language based on Dungeons and Dragons. It is built on C++.  

### Demo Code

##### Code:
roll initiative <>  
reroll nat kobold Gary 5?  
reroll nat dragon Bob \*Hello World*?  

dungeon 3 floors <>  
say Bob?  
\><  

nat kobold i 4?  
dungeon i floors <>  
quest i is 3 //  
say \*Woo*?  
\\\  
railroad //  
say \*no woo*?
\\\  
reroll i – 1?  
\><  

nat kobold j 5?  
dungeon j floors <>  
quest j CD 2 //  
say \*smol*?  
\\\  
railroad //  
say \*beeg*?  
\\\  
reroll j – 1?  
\><  
\><  

##### Output:
Hello World  
no woo  
Woo  
no woo  
no woo  
beeg  
beeg  
beeg  
smol  
smol  

### Syntax Rules  

- All lines end with the ? character  
- Single line comments begin with \_^
- Multi-line comments begin and end with ||
- Blocks of code in an if-else statement begin with // and end with \\\. All other blocks of code begin with <> and end with \><  
- Strings begin and end with the \* character  
- Binary operators: & for addition, – for subtraction, · for multiplication, and ÷ for division. "is" is used for equality comparison (== in C++). "AC" is used for \>, "DC" is used for \>=, "CA" is used for <, and "CD" is used for <=.