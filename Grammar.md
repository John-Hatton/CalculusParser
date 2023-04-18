# Equation Parsing Grammar

    <expression> ::= <term> { ( "+" | "-" ) <term> }
    <term> ::= <factor> { ( "*" | "/" ) <factor> }
    <factor> ::= <number> | <variable> | <function> | "(" <expression> ")"
    <number> ::= <digit> { <digit> } [ "." <digit> { <digit> } ]
    <variable> ::= <letter>
    <function> ::= <letter> "(" <expression> ")"
    <digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
    <letter> ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z"
