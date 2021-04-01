#include "viewport.h"

#include "GL/glew.h"

#include "gdkmm/glcontext.h"
#include "glm/glm.hpp"
#include "gdk/gdkkeys.h"

#include <iostream>

namespace editor
{

Viewport::Viewport()
  : m_initialized(false)
{
  set_has_depth_buffer(true);

  add_events(Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);

  signal_render().connect(sigc::mem_fun(*this, &Viewport::gl_render));
  signal_resize().connect(sigc::mem_fun(*this, &Viewport::gl_resize));
}

void Viewport::initialize(Gdk::GLContext *ctx)
{
  ctx->make_current();

  glewExperimental = true;

  // Create an OpenGL Context
  glewInit();

  m_initialized = true;
}

void Viewport::render_scene()
{
  // Render the scene graph
}

bool Viewport::gl_render(const Glib::RefPtr<Gdk::GLContext> &ctx)
{
  if (!m_initialized) {
    initialize(ctx.get());
  }

  this->throw_if_error();

  // TODO: Perform OpenGL Operations here

  glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  render_scene();

  glFlush();

  return true;
}

void Viewport::gl_resize(int width, int height)
{

}

bool Viewport::on_key_press_event(GdkEventKey *key_event)
{
  auto key = key_event->keyval;

  if (key == GDK_KEY_Escape) {
    // Do something
  }

  // Return false. All events are sunk into the 3D view
  return false;
}

bool Viewport::on_motion_notify_event(GdkEventMotion *motion_event)
{
  glm::vec2 mousePosition(motion_event->x, motion_event->y);

  // Do something with the mouse position
  return false;
}

}
