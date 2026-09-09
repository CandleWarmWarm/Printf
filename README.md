*This project is part of the 42 curriculum by nsomjaip.*

## Description

`ft_printf` is a re-implementation of the `printf` function from `<stdio.h>`.
The goal is to understand how `printf` works internally — parsing format
strings, handling variadic arguments, and converting/formatting output —
so this knowledge can be reused in future projects.

## Instruction

```bash
make
```

This compiles `libftprintf.a`.

Compile your source files together with the library:

```bash
cc *.c libftprintf.a
```

```bash
make          # build
make clean    # remove .o files
make fclean   # remove .o files + libftprintf.a
make re       # rebuild everything from scratch
```

Then include the header and call `ft_printf` like the standard `printf`.

## Supported conversions

- `%c` – character // use for print single character
- `%s` – string // use for print string if input NULL will print (null)
- `%p` – pointer // use for print pointer address if input NULL will print (nil) cuz 0x0 might make confusing
- `%d` / `%i` – decimal integer // %d and %i is not different in printf but diff in scanf so just print decimal numb
- `%u` – unsigned integer // print unsigned int
- `%x` / `%X` – hexadecimal // x for lower and X for upper
- `%%` – percent sign // just print %

## Resources

I used AI assistance to test edge cases, debug my function, and better
understand how `va_list`, `va_start`, `va_arg`, and `va_end` work.
and some youtube for understand 1980s printf work.