#pragma once

#include <memory>

#include "viewport.h"

#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/applicationwindow.h>

namespace editor
{

class EditorWindow : public Gtk::ApplicationWindow
{

public:
  EditorWindow();
  virtual ~EditorWindow();

protected:

  Gtk::Grid m_grid;

  //Member widgets:
  Viewport m_viewport;
};

}
