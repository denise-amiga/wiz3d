#include "../lib/litelibs/litegfx.h"
#include "pixmap.h"
#include "texture.h"
#include "util.h"

static bool_t _texture_filtering = TRUE;

struct texture_t
{
  int     refcount; /* use int instead of size_t because non counted textures can have negative values here */
  ltex_t* ptr;
};

struct texture_t* texture_new(int width, int height)
{
  struct texture_t* tex = _alloc(struct texture_t);
  tex->refcount = 0;
  tex->ptr = ltex_alloc(width, height, _texture_filtering);
  return tex;
}

struct texture_t* texture_load(const char* filename)
{
  struct pixmap_t* pixmap;
  struct texture_t* tex;

  /* load pixmap */
  pixmap = pixmap_load(filename);
  if (!pixmap) return NULL;

  /* create texture */
  tex = texture_new(pixmap_width(pixmap), pixmap_height(pixmap));
  if (tex) texture_setpixels(tex, pixmap);

  /* delete pixmap */
  pixmap_delete(pixmap);

  return tex;
}

void texture_retain(struct texture_t* texture)
{
  ++texture->refcount;
}

void texture_release(struct texture_t* texture)
{
  if ( --texture->refcount == 0 )
  {
    texture_delete(texture);
  }
}

void texture_delete(struct texture_t* texture)
{
  ltex_free(texture->ptr);
  free(texture);
}

int texture_width(struct texture_t* texture)
{
  return texture->ptr->width;
}

int texture_height(struct texture_t* texture)
{
  return texture->ptr->height;
}

void texture_setpixels(struct texture_t* texture, struct pixmap_t* pixmap)
{
  if (texture->ptr->width == pixmap_width(pixmap) && texture->ptr->height == pixmap_height(pixmap))
  {
    ltex_setpixels(texture->ptr, _pixmap_ptr(pixmap));
  }
}

void texture_setfilter(bool_t filter)
{
  _texture_filtering = filter;
}

void* _texture_ptr(struct texture_t* texture)
{
  return texture ? texture->ptr : NULL;
}