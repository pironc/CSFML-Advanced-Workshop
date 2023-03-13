# Introduction to CSFML

##### This workshop aims to teach you the basics of CSFML. You have a working window, but now we'll add some stuff into it. Textures, sprites, make sure to understand the important terms by taking a look at the [official website]().

##### It's written in SFML but it doesn't matter that much to understand the concepts, however if you wanna check out the types, structures, functions and their functionalities, you might wanna refer to [this unofficial CSFML documentation](https://26.customprotocol.com/csfml/). It will be really useful, trust me !

###### After the workshop, the corrected exercises will be in separated files, each one of them with the added functionality of the previous one and available for you to use and understand.

<br>

### Step 0 - Setup

In order to get started with the CSFML, you'll have to install the CSFML library.

#### Linux

You should already have it installed from the C Pool, or by using the ``` build_csfml.sh ``` executable file available in the repository.

#### MacOS

If you're using a Mac M1 chip, the 2.5.1 library is already built in the ``` __OSX__ ``` folder. If you wish to build it for another version or processor (X86 / ARM), please refer to the official documentation.

The most common folder to find your built library is in ``` /opt/homebrew/Cellar/csfml/ ```. Your can take the ``` include ``` and ``` lib ``` file and replace the existing ones in the ``` ___OSX__ ``` folder in the repository.

If there are any deprecated functions, you can removed them from the compiled library to avoid unnecessary warnings.

**You should now be able to open a window in CSFML.**

<br>

### Creating scenes

For your upcoming RPG, you should probably need a scenes system in order to switch between your menus, settings or even different scenes of your game, or even when entering a building or moving to a different area.
The workshop will mainly consist of this scene manager, as it is pretty big and you will have to quite a bit of coding.

><details>
> <summary>Hint</summary>
>
> This one will be a bit trickier. The best method in my opinion is to use an array of function pointers.
> It may sound like nothing in your mind right now, but it will basically be holding different functions.
>
> Think about it like an array of strings. Accessing the first element (yourarray[0]) will return you a string,
> but using it with functions instead of strings, you will be able to call the functions from this array of function pointers.
>
> It could look a bit like : ```void (*scene_manager[])(void) = {menu, settings, gameplay};```
> I recommend that you take a look at it online to understand how it works.
>
</details>

