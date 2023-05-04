#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
enum FieldState
{
    Empty,Player1,Player2
};
class Field
{
protected:
public:
    FieldState State;
    Field(FieldState startState= Empty);
};
#endif // FIELD_H_INCLUDED
