import logo from './logo.svg';
import './App.css';
import Page from './pages/page';
import Button from './components/Button/Button';
function App() {
  return (
    <div className="App">
      <Page/>
      <Button text = "Aarya" heading="Waoo"/>
      <Button text = "Dhairya" heading="Waoo Daddy"/>
      <Button text = "Dhruv" heading="Waoo Mommy"/>
      <Button text = "Aditya"/>
    </div>
  );
}

export default App;
