module Main

import Data.Vect


data DataStore : Type where
  MkData : (size : Nat) ->
           (items : Vect size String) ->
           DataStore

size : DataStore -> Nat
size (MkData size' items') = size'

items : (store : DataStore) -> Vect (size store) String
items (MkData size' items') = items'

addToStore : DataStore -> String -> DataStore
addToStore (MkData size items) newItem = MkData _ (addToData items)
  where 
    addToData : Vect old String -> Vect (S old) String
    addToData [] = [newItem]
    addToData (x :: xs) = x :: addToData xs 



data Command = Add String
             | Get Integer
             | Quit


parseArguements : (cmd : String) -> (args : String) -> Maybe Command
parseArguements "add" args = Just (Add args)
parseArguements "get" val = case all isDigit (unpack val) of
                                 False => Nothing
                                 True  => Just (Get (cast val))
parseArguements "quit" ""  = Just Quit
parseArguements _ _ = Nothing

parse : String -> Maybe Command
parse inputString = case span (/= ' ') inputString of 
                        (cmd, args) => parseArguements cmd (ltrim args) 



processCommand : (cmd : Command) -> (store : DataStore) -> Maybe (String, DataStore)
processCommand (Add inpStr) store = Just("ID " ++ show (size store) ++ "\n", addToStore store inpStr)
processCommand (Get x) store = ?processCommand_rhs_2
processCommand Quit store = Nothing 

processInput : DataStore -> String -> Maybe (String, DataStore)
processInput store inputString = case parse inputString of
                                      Nothing => Just ("Invalid Command\n", store)
                                      Just cmd => processCommand cmd store


main : IO ()
main = replWith (MkData _ []) "Command: " processInput 
