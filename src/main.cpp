
#include <gtkmm.h>

#include "main_window.h"

int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

  editor::EditorWindow window;

  return app->run(window);
}
