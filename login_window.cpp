#include "login_window.hpp"
#include "gtkmm/dialog.h"
#include "gtkmm/enums.h"
#include "gtkmm/messagedialog.h"
#include <iostream>

LoginWindow::LoginWindow() {
  this->set_title("Login Application");
  this->set_default_size(400, 200);
  this->set_visible(true);

  isLogged = false;

  this->setupHierarchy();
  this->initializeChildrens();
}

void LoginWindow::initializeChildrens() {
  // Main Grid
  this->mainGrid.set_visible(true);
  this->mainGrid.set_column_spacing(10);
  this->mainGrid.set_row_spacing(10);
  this->mainGrid.set_margin_top(20);
  this->mainGrid.set_margin_left(20);

  // Username Label
  this->usernameLabel.set_visible(true);
  this->usernameLabel.set_can_focus(false);
  this->usernameLabel.set_label("Username: ");

  // Username Input
  this->usernameInput.set_visible(true);
  this->usernameInput.set_can_focus(true);

  // Password Label
  this->passwordLabel.set_visible(true);
  this->passwordLabel.set_can_focus(false);
  this->passwordLabel.set_label("Password: ");

  // Password Input
  this->passwordInput.set_visible(true);
  this->passwordInput.set_visibility(false);
  this->passwordInput.set_can_focus(true);
  this->passwordInput.set_input_purpose(Gtk::INPUT_PURPOSE_PASSWORD);

  // Login Button
  this->loginBtn.set_visible(true);
  this->loginBtn.set_label("Login");
  this->loginBtn.set_can_focus(true);
  this->loginBtn.signal_clicked().connect([=]() {
    if (this->usernameInput.get_text() == "admin" &&
        this->passwordInput.get_text() == "admin") {
      this->onLoginDialogLabel.set_text("Login efetuado!");
      isLogged = true;
    } else {
      this->onLoginDialogLabel.set_text("Usuário ou senha incorreto");
      isLogged = false;
    }

    this->onLoginDialog.show();
  });

  // On Login Dialog
  this->onLoginDialog.set_title("Login efetuado com sucesso!");
  this->onLoginDialog.set_default_size(100, 100);
  this->onLoginDialog.set_modal(true);

  this->onLoginDialog.get_content_area()->set_margin_top(10);
  this->onLoginDialog.get_content_area()->set_margin_left(10);

  this->onLoginDialog.add_button("Ok", 0);

  this->onLoginDialog.signal_response().connect([=](int id) {
    if (id == 0) {
      this->onLoginDialog.close();

      if (isLogged) {
        this->close();
      }
    }
  });

  this->onLoginDialogLabel.set_visible(true);
  this->onLoginDialogLabel.set_can_focus(false);
}

void LoginWindow::setupHierarchy() {
  this->add(this->mainGrid);

  this->mainGrid.attach(this->usernameLabel, 0, 0);
  this->mainGrid.attach(this->usernameInput, 1, 0);

  this->mainGrid.attach(this->passwordLabel, 0, 1);
  this->mainGrid.attach(this->passwordInput, 1, 1);

  this->mainGrid.attach(this->loginBtn, 0, 2);

  this->onLoginDialog.get_content_area()->add(onLoginDialogLabel);
}
