int main() {
  sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({INIT_WIDTH, INIT_HEIGHT}), "MyProgram");
  window.setFramerateLimit(144);

  sf::Vector2f sz({50, 50});
  sf::RectangleShape r0(sz);
  sf::RectangleShape r1(r0); r1.setFillColor(sf::Color::Red)    ; r1.move({20, 20});
  sf::RectangleShape r2(r0); r2.setFillColor(sf::Color::Green)  ; r2.move({INIT_WIDTH - 20 - sz.x, 20});
  sf::RectangleShape r3(r0); r3.setFillColor(sf::Color::Blue)   ; r3.move({20, INIT_HEIGHT - 20 - sz.y});
  sf::RectangleShape r4(r0); r4.setFillColor(sf::Color::Magenta); r4.move({INIT_WIDTH - 20 - sz.x, INIT_HEIGHT - 20 - sz.y});

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->scancode) {
          case sf::Keyboard::Scancode::Q:
            window.close();
            break;
          default:
            break;
        };
      }
    }

    window.clear();
    window.draw(r1);
    window.draw(r2);
    window.draw(r3);
    window.draw(r4);
    window.display();
  }
}
