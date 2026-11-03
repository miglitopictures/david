A script writing program for the terminal.

## philosophy
>70 scenes = screenplay

I first discovered this way of writing scripts from David Lynch. As far as I remember, from reading his biography 'Room to Dream', he learned it from a teacher called Frank Daniel, at the American Film Institute.

## install
```bash
gcc -o david david.c
```
Then move `david` somewhere in your `$PATH`, like `~/.local/bin` or `/usr/local/bin`.

## usage
Create your directory and go to it.
```bash
mkdir blue-velvet && cd blue-velvet
```
david keeps your scenes in a `scenes.david` file inside the current directory, so one directory = one movie.

Start writing scenes with david.
```bash
david "Blue sky, red roses, a white picket fence."
```
```
Written 1 item to './scenes.david'.
```

Read everything you wrote so far.
```bash
david
```
```
 1 - Blue sky, red roses, a white picket fence.
 2 - A fire truck glides past in slow motion; a fireman waves.
```

Commands:

`-r` `-regret`
deletes the last scene you wrote.
```bash
david -regret
```

`-p` `-progress`
shows your progress into the movie (70 scenes).
```bash
david -progress
```
```
02 out of 70.
```

## limits
- A scene holds up to 255 characters.
- `david` lists up to 128 scenes.

## example
In `examples/blue-velvet`, you will find 1986's masterpiece Blue Velvet broken into 70 scenes. This decomposition was made for fun and curiosity using Claude and should not be taken seriously. Others like it can be found in `examples/`.

Go into one of the example directories and run `david` to read it.

## disclaimer
The code was written by me without using AI, but I DID use Claude to help correct grammar and complete certain parts of the `readme.md` . I do NOT know if this fact holds any weight, but some people seem to care. Just being transparent.
