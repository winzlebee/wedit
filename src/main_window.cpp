#include "main_window.h"

#include "viewport.h"

#include "gtkmm/container.h"

namespace editor
{

EditorWindow::EditorWindow()
{
  add(m_viewport);

  m_viewport.show();

  set_show_menubar(true);
}

EditorWindow::~EditorWindow()
{

}

}
