#pragma once

#include <gtkmm/glarea.h>

namespace Gdk
{
  class GLContext;
}

namespace editor {

class Viewport : public Gtk::GLArea
{
public:
  Viewport();

  sigc::signal<void> s_on_initialized;
  sigc::signal<void> s_on_failed;

protected:

  void render_scene();

  bool gl_render(const Glib::RefPtr<Gdk::GLContext> &ctx);

  void gl_resize(int width, int height);

  void initialize(Gdk::GLContext *ctx);

  bool on_key_press_event(GdkEventKey *key_event) override;

  bool on_motion_notify_event(GdkEventMotion *motion_event) override;

private:
  void initialize();

  bool m_initialized;
};

}
