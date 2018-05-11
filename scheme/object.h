#ifndef SCHEME_C_OBJECT_H
#define SCHEME_C_OBJECT_H

#include <stddef.h>
#include "type.h"

typedef struct SchemeObject {
    SchemeObjectType type;
    union {
        struct {
            char value;
        } boolean;
        struct {
            char* value;
        } symbol;
        struct {
            long value;
        } fixnum;
        struct {
            char value;
        } character;
        struct {
            char* value;
        } string;
        struct {
            struct SchemeObject* car;
            struct SchemeObject* cdr;
        } pair;
    } data;
} SchemeObject;

extern SchemeObject* AllocObject();

extern SchemeObject* MakeFixnum(long value);

extern char IsFixnum(SchemeObject* obj);

extern void InitScheme();

extern SchemeObject* True;
extern SchemeObject* False;
extern SchemeObject* The_Empty_List;
extern SchemeObject* Symbol_Table;
extern SchemeObject* Quote_Symbol;

extern char IsTheEmptyList(SchemeObject* obj);

extern char IsBoolean(SchemeObject* obj);

extern char IsFalse(SchemeObject* obj);

extern char IsTrue(SchemeObject* obj);

extern SchemeObject* MakeCharacter(char value);

extern char IsCharacter(SchemeObject* obj);

extern SchemeObject* MakeString(char* value);

extern char IsString(SchemeObject* obj);

extern SchemeObject* Cons(SchemeObject* car, SchemeObject* cdr);

extern char IsPair(SchemeObject* obj);

extern SchemeObject* Car(SchemeObject* pair);

extern void SetCar(SchemeObject* pair, SchemeObject* value);

extern SchemeObject* Cdr(SchemeObject* pair);

extern void SetCdr(SchemeObject* pair, SchemeObject* value);

extern SchemeObject* MakeSymbol(char* value);

extern char IsSymbol(SchemeObject* obj);

extern char IsSelfEvaluting(SchemeObject* exp);

extern char IsTaggedList(SchemeObject* exp, SchemeObject* tag);

extern char IsQuote(SchemeObject* exp);

extern SchemeObject* TextOfQuotation(SchemeObject* exp);

#endif //SCHEME_C_OBJECT_H
