# Introduction
...

# Modules

## colbox
This module allows the addition of static collision boxes to your scene.

`void colbox_add(float minx, float miny, float minz, float maxx, float maxy, float maxz)`

Adds a new collision box to the scene within the given boundaries.

`void colbox_clear()`

Clears all collision boxes.

## color
Colors are stored as standard integers. Using this module, you can extract the RGBA components from a given color, multiply the components by a given factor and change the alpha alone. The following constants with common colors are also predefined:

| Color values |
| ---------- |
| `_COLOR_RED` |
| `_COLOR_GREEN` |
| `_COLOR_BLUE` |
| `_COLOR_CYAN` |
| `_COLOR_MAGENTA` |
| `_COLOR_YELLOW` |
| `_COLOR_BLACK` |
| `_COLOR_WHITE` |
| `_COLOR_GRAY` |
| `_COLOR_LIGHTGRAY` |
| `_COLOR_DARKGRAY` |
| `_COLOR_ORANGE` |
| `_COLOR_BROWN` |

`int color_rgb(int r, int g, int b)`

Returns a fully opaque color with the given RGB values. Each component should be given in the range 0...255.

`int color_rgba(int r, int g, int b, int a)`

Returns a color with the given RGBA values. Each component should be given in the range 0...255.

`int color_red(int color)`

Returns the red value of the given color, in the range 0...255.

`int color_green(int color)`

Returns the green value of the given color, in the range 0...255.

`int color_blue(int color)`

Returns the blue value of the given color, in the range 0...255.

`int color_alpha(int color)`

Returns the alpha value of the given color, in the range 0...255.

`int color_changealpha(int color, int new_alpha)`

Returns a color with the same RGB values of the given color and the specified alpha value, which should be in the range 0...255.

`int color_multiply(int color, float factor)`

Multiplies the RGBA values of the given color by the specified factor. All values are clamped to the range 0...255.

## input
Support keyboard and mouse input. Mouse buttons are represented by the following constants:

| Mouse buttons |
| ------------- |
| `_MOUSE_LEFT` |
| `_MOUSE_RIGHT` |
| `_MOUSE_MIDDLE` |

There are also constants defined for every key, i.e. `_KEY_ESC`, `_KEY_SPACE`, `_KEY_ENTER`, `_KEY_UP`, `_KEY_A`, `_KEY_LEFT_CONTROL`, `_KEY_LEFT_SUPER`, etc.

`void input_setmousevisible(bool_t visible)`

Shows or hides the mouse pointer.

`void input_setmouseposition(int x, int y)`

Moves the mouse pointer to the specified coordinates.

`int input_mousex()`

Returns the x coordinate of the mouse pointer, measured as the distance from the left of the screen.

`int input_mousey()`

Returns the y coordinate of the mouse pointer, measured as the distance from the top of the screen.

`bool_t input_mousedown(int b)`

Tells whether the given mouse button is pressed or not.

`bool_t input_keydown(int k)`

Tells whether the given key is pressed or not.

## light
Micron allows the definition of up to 8 lights in the scene. Directional and point lights are supported. Each light is represented by the following structure:

```
struct light_t
{
  float x, y, z;
  float pitch, yaw;
  int   type;
  int   color;
  float range;
};
```

`struct light_t* light_new(int type)`

Creates a new light of the given type and returns a pointer to it. Supported types are `_LIGHT_DIRECTIONAL` and `_LIGHT_POINT`.

`void light_delete(struct light_t* light)`

Deletes the given light. You should not use the pointer after this.

`void light_move(struct light_t* light, float x, float y, float z)`

Moves the specified light by the given amount in local coordinates. For example, a positive z value will move the light forward in the direction that it is facing.

`void light_turn(struct light_t* light, float pitch, float yaw)`

Turns the light by the given pitch and yaw amounts.

`void light_setambient(int color)`
Sets the global ambient color of the scene.

`int light_ambient()`
Gets the global ambient color of the scene.

## log
The log module allows to print messages to the log file (which is the file "log.txt" that will be automatically created on the game folder).

`void log_info(const char* msg)`

Writes information to the log file.

`void log_warning(const char* msg)`

Writes a warning to the log file.

`void log_error(const char* msg)`

Writes an error to the log file. This will show a message box with the error message and will cause the program to abort.

## material

Materials define the way that 3D objects look. A material is defined by the following structure:

```
struct material_t
{
  struct texture_t* texture;
  int               diffuse;
  int               emissive;
  int               specular;
  float             shininess;
  int               blend;
  int               flags;
  int               shininesspower;
};
```

* `texture`: Color texture.
* `diffuse`: Diffuse color that indicates how it responds to lighting.
* `emissive`: Color that the object emits by itself, without the need to receive lighting.
* `specular`: Color of the specular reflections that this object produces.
* `shininess` A floating point value in the range 0...1 that indicates how shiny the object is. The shinier an object is, the more intense and concentrated its specular reflections are.
* `blend`: Specified how the object blends with its surroundings. Can be:
  * `_BLEND_SOLID`: The material is fully opaque.
  * `_BLEND_ALPHA`: Parts of the object can appear as transparent depending on the alpha of the texture and diffuse color.
  * `_BLEND_ADD`: The material is added to whatever is behind it. It looks as a transparent object (except for the white parts that would look opaque), and this mode is usually used on elements such as fire or sparks, because it makes the object appear brighter.
  * `_BLEND_MUL`: The material is multiplied with whatever is beneath it. Rarely used, but it is useful to darken or tint the background using the material.
* `flags`: Enables or disables some visual properties of the material. It can be a bitwise combination of:
  * `_FLAG_CULL`: Enables backface culling. This makes the backside of objects visible. Normally disabled with transparent objects.
  * `_FLAG_DEPTHWRITE`: Enables writing to the depth buffer. Normally disabled for some transparent materials like glass.
  * `_FLAG_LIGHTING`: Enables the material ability to respond to lighting.
  * `_FLAG_FOG`: Enables the material sensitivity to fog.
  * `_FLAG_ALL`: Enables all flags. This is the default setting.
* `shininesspower`: Indicates how fast the specular reflections vanish. It is a value in the range 0...128 that, multiplied by the shininess of the object, is used as exponent in the Blinn-Phong specular calculation. The default value is -1, which means that the global shininess power set by `material_setshininesspower` will be used.

You can get the material that an object uses and modify any of these properties.

`int material_shininesspower()`

Returns the default shininess power for all materials whose shininess power value is -1.

`void material_setshininesspower(int power)`

Sets the default shininess power for all materials whose shininess power value is -1. It has to be in the range 0..128, and initially has the value 128.

## memory

Micron can allocate and manipulate memory buffers with this module. It defines an opaque structure `memory_t`.

`struct memory_t* memory_new(int size)`

Allocates a memory buffer of the specified size and returns a pointer to it.

`void memory_delete(struct memory_t* memory)`

Frees the specified memory buffer. You should not use the pointer after this.

`int memory_size(const struct memory_t* memory)`

Returns the size in bytes of the specified memory buffer.

`unsigned char memory_byte(const struct memory_t* memory, int offset)`

Reads an unsigned byte (0...255) from the specified offset in the memory buffer.

`unsigned short memory_short(const struct memory_t* memory, int offset)`

Reads a short (2 bytes, range 0...65535) from the specified offset in the memory buffer.

`int memory_int(const struct memory_t* memory, int offset)`

Reads a signed integer from the specified offset in the memory buffer.

`float memory_float(const struct memory_t* memory, int offset)`

Reads a 32 bit float from the specified offset in the memory buffer.

`double memory_double(const struct memory_t* memory, int offset)`

Reads a 64 bit float from the specified offset in the memory buffer.

`void memory_setbyte(struct memory_t* memory, int offset, unsigned char val)`

Writes an unsigned byte to the specified offset in the memory buffer.

`void memory_setshort(struct memory_t* memory, int offset, unsigned short val)`

Writes an unsigned short to the specified offset in the memory buffer.

`void memory_setint(struct memory_t* memory, int offset, int val)`

Writes a signed integer to the specified offset in the memory buffer.

`void memory_setfloat(struct memory_t* memory, int offset, float val)`

Writes a 32 bit float to the specified offset in the memory buffer.

`void memory_setdouble(struct memory_t* memory, int offset, double val)`

Writes a 64 bit float to the specified offset in the memory buffer.

## object

Objects are the 3D elements of the scene. They have a position, rotation, scale and a mesh. A mesh contains a set of vertices and indices that form the geometry of the object, grouped in buffers, with one material per buffer. An object is represented by the following struct:

```
struct object_t
{
  float x, y, z;
  float pitch, yaw, roll;
  float sx, sy, sz;
  int   billboard;
  int   colmode;
  float radius;
  int   animmode;
  float animspeed;
  float animframe;
  int   animmin;
  int   animmax;
};
```

* `x`, `y`, `z`: Position.
* `pitch`, `yaw`, `roll`: Rotation.
* `sx`, `sy`, `sz`: Scale.
* `billboard`: Whether the object should rotate automatically to face the viewer.
  * `_BILLBOARD_NONE`: Does not rotate to face the camera.
  * `_BILLBOARD_FACE`: Rotates to face the camera.
  * `_BILLBOARD_UPRIGHT`: Rotates only yaw to face the camera.
* `colmode`: Collision mode:
  * `_COL_NONE`: No collision.
  * `_COL_SPHERE`: Defines a collision sphere around the object of the specified `radius`.
  * `_COL_BOX`: Defines a collision box around the object based on its size.
* `radius`: Radius of the collision sphere when the collision mode is `_COL_SPHERE`.
* `animmode`: Animation mode if the object's mesh is animated:
  * `_ANIM_STOP`: Does not animate.
  * `_ANIM_PLAY`: Plays the animation once.
  * `_ANIM_LOOP`: Plays the animation in a loop.
* `animspeed`: Relative speed in respect to the global animation fps. Default value is 1.
* `animframe`: The current animation frame.
* `animmin`: First frame to use in the animation sequence.
* `animmax`: Last frame to use in the animation sequence.

You can directly set any of these property.

`struct object_t* object_new()`

Creates a new object with an empty mesh.

`struct object_t* object_newcube()`

Creates a new object with a cube mesh.

`struct object_t* object_newquad()`

Creates a new object with a quad mesh.

`struct object_t* object_newtriangle()`

Creates a new object with a triangle mesh.

`struct object_t* object_load(const char* filename)`

Loads a mesh from disk, in the .md2 or .assbin formats.

`struct object_t* object_clone(const struct object_t* object)`

Creates a clone of the given object, sharing the same mesh. You can modify the materials, but modifying the mesh will change the original and all other clones.

`void object_delete(struct object_t* object)`

Deletes the given object.

`int object_addbuffer(struct object_t* object)`

Adds a new buffer to the mesh that the object uses. A buffer is a set of vertices and triangles with one material.

`int object_numbuffers(struct object_t* object)`

Returns the number of buffers that the mesh in the object contains. Since each buffer has a material, this is also the number of materials in the mesh.

`int object_addvertex(struct object_t* object, int buffer, float x, float y, float z, float nx, float ny, float nz, float u, float v, int color)`

Adds a new vertex to the specified buffer index. returns the index of the vertex within the buffer.

`int object_addtriangle(struct object_t* object, int buffer, int v0, int v1, int v2)`

Adds a triangle to the specified buffer index. You must pass the index to the three vertices that form the triangle. Returns the index of the triangle.

`void object_rebuildmesh(struct object_t* object)`

Rebuilds the mesh bouding box. You should call this function after adding or modifying its vertices or indices.

`struct material_t* object_material(struct object_t* object, int index)`

Returns the material with the specified index.

`float object_width(const struct object_t* object)`

Returns the total width of the object, taking its scale into account.

`float object_height(const struct object_t* object)`

Returns the total height of the object, taking its scale into account.

`float object_depth(const struct object_t* object)`

Returns the total depth of the object, taking its scale into account.

`float object_minx(const struct object_t* object)`

Returns the minimum x coordinate that the mesh of this object occupies, taking its position into account.

`float object_miny(const struct object_t* object)`

Returns the minimum y coordinate that the mesh of this object occupies, taking its position into account.

`float object_minz(const struct object_t* object)`

Returns the minimum z coordinate that the mesh of this object occupies, taking its position into account.

`float object_maxx(const struct object_t* object)`

Returns the maximum x coordinate that the mesh of this object occupies, taking its position into account.

`float object_maxy(const struct object_t* object)`

Returns the maximum y coordinate that the mesh of this object occupies, taking its position into account.

`float object_maxz(const struct object_t* object)`

Returns the maximum z coordinate that the mesh of this object occupies, taking its position into account.

`bool_t object_move(struct object_t* object, float x, float y, float z)`

Moves the specified object by the given amount in local coordinates. For example, a positive z value will move the object forward in the direction that it is facing. If collision is enabled for the object, it is ensured that it does not penetrate static collision objects. Returns whether the object collided any static collision boxes or not. If it did, the object will not have moved the specified amount in at least one of the three axis, to avoid penetrating the collision box.

`void object_turn(struct object_t* object, float pitch, float yaw, float roll)`

Turns the object with the given pitch, yaw and roll.

`bool_t object_collidesboxes(struct object_t* object)`

Returns whether the object is colliding any static collision boxes.

`bool_t object_collidesobject(struct object_t* object, struct object_t* object2)`

Returns whether the given objects collide.

`void object_draw(struct object_t* object)`

Draws the given object to the screen.

`int object_numframes(const struct object_t* object)`

Returns the number of animation frames that the mesh of the given object contains.

`void object_setanimfps(float fps)`

Set the global animation frames per second. The default value is 16.

`float object_animfps()`

Get the global animation frames per second.

## pixmap